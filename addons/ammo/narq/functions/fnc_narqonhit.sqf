#define CSW_NARQTIME 20 // TODO: move into a mission setting at some point

params ["_whohit", "_shooter"];
if (_whohit == _shooter) exitWith {}; // Skip if shooter shot self
if (!isPlayer _shooter) exitWith {};  // Skip if shooter is AI
if (getText(configFile >> "CfgVehicles" >> typeOf _whohit >> "simulation") == "UAVPilot") exitWith {}; // skip if who hit was a UAV false AIi

// Cache shooter weapon and magazine
private _weapon = currentWeapon _shooter;
private _mag = currentMagazine _shooter;
private _ammo = getText(configFile >> "CfgMagazines" >> _mag >> "ammo");

// Exit early if not narq ammo
private _isNarqAmmo = _ammo in [
    "Tenthed_6Rnd_127x40_Cyl_NARQ",
    "Tenthed_6Rnd_127x40_Cyl_NARQ_Tracer",
    "Tenthed_B_127x40_NARQ_Ball"
];
if (!_isNarqAmmo) exitWith {};

diag_log "[Narq] Narq ammo detected.";

// Exit early if already narqed
private _oldNarqedUntilTime = _whohit getVariable ["CSW_isNarqedUntil", CBA_missionTime - 1];
if (_oldNarqedUntilTime >= CBA_missionTime) exitWith {
    diag_log format ["[Narq] Target %1 is already narqed until %2. Skipping.", _whohit, _oldNarqedUntilTime];
};

// Exit early for zombies
// because zombies shouldnt be able to be narqed
if (_whohit call ace_common_fnc_isZombie) exitWith {
    diag_log format ["[Narq] Target %1 is a zombie. Narq has no effect.", _whohit];
};

// Cache narq timing
//private _oldNarqedUntilTime = _whohit getVariable ["CSW_isNarqedUntil", CBA_missionTime - 1];
private _newTime = CBA_missionTime + CSW_NARQTIME;
_whohit setVariable ["CSW_isNarqedUntil", _newTime, true];

if (_oldNarqedUntilTime >= CBA_missionTime) exitWith {
    if (vehicle _whohit == _whohit && _oldNarqedUntilTime < _newTime - 2) then {
        [_whohit] call CSW_fnc_dropWeapon;
    };
};

// Begin NARQ logic
[_whohit, _shooter, _oldNarqedUntilTime] spawn {
    params ["_whohit", "_shooter", "_oldNarqedUntilTime"];
    private _wasStopped = false;
    private _inVehicle = !(vehicle _whohit == _whohit);

    if (!_inVehicle) then {
        [_whohit, "AcinPercMstpSrasWrflDnon_agony"] remoteExecCall ["switchMove", 0];
        sleep 5;
        [_whohit, "Static_Dead"] remoteExecCall ["switchMove", 0];
        _whohit setDir (195 + getDir _whohit);

        if (isNil "ace_medical_fnc_setUnconscious") then {
            _wasStopped = !(stopped _whohit);
            if (_wasStopped) then {
                [_whohit, true] remoteExecCall ["stop", 0];
                [_whohit, true] remoteExecCall ["ace_common_fnc_disableAI", _whohit];
            };
        };

        [_whohit] call CSW_fnc_dropWeapon;

        if (!isNil "ace_medical_fnc_setUnconscious") then {
            sleep 0.5;
            [_whohit, true, CSW_NARQTIME, true] call ace_medical_fnc_setUnconscious;
        };
    } else {
        if (isNil "ace_medical_fnc_setUnconscious") then {
            _whohit setVariable ["CSW_WakeUpAnimVehicle", [animationState _whohit, vehicle _whohit], true];
            private _anim = [_whohit] call ace_common_fnc_getDeathAnim;
            [_whohit, _anim] remoteExecCall ["playActionNow", 0];

            _wasStopped = !(stopped _whohit);
            if (_wasStopped) then {
                [_whohit, true] remoteExecCall ["stop", 0];
                [_whohit, true] remoteExecCall ["ace_common_fnc_disableAI", _whohit];
            };
        } else {
            [_whohit, true, CSW_NARQTIME, true] call ace_medical_fnc_setUnconscious;
        };
    };

    // Wake-up logic
    [_whohit, _wasStopped] spawn {
        params ["_whohit", "_wasStopped"];
        waitUntil { (_whohit getVariable ["CSW_isNarqedUntil", 0]) <= CBA_missionTime };

        if (_wasStopped) then {
            [_whohit, false] remoteExecCall ["stop", 0];
            [_whohit, false] remoteExecCall ["ace_common_fnc_disableAI", _whohit];
        };

        if (!isNil "ace_medical_fnc_setUnconscious") then {
            [_whohit, false, 0, true] call ace_medical_fnc_setUnconscious;
        };

        if (vehicle _whohit == _whohit) then {
            [_whohit, "AmovPpneMstpSnonWnonDnon"] remoteExecCall ["switchMove", 0];
        } else {
            (_whohit getVariable ["CSW_WakeUpAnimVehicle", ["", objNull]]) params ["_anim", "_vehicle"];
            if (_anim != "" && {vehicle _whohit == _vehicle}) then {
                [_whohit, _anim] remoteExecCall ["switchMove", 0];
            };
        };
    };
};

diag_log format ["[Narq] %1 shot %2 with %3 at %4", _shooter, _whohit, _ammo, CBA_missionTime];
