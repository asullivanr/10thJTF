#define CSW_NARQTIME 20

params ["_whohit", "_shooter"];
if (_whohit == _shooter) exitWith {};
if (getText(configFile >> "CfgVehicles" >> typeOf _whohit >> "simulation") == "UAVPilot") exitWith {};

private _weapon = currentWeapon _shooter;
private _mag = currentMagazine _shooter;
private _ammo = getText(configFile >> "CfgMagazines" >> _mag >> "ammo");

//diag_log format ["[Narq] Checking hit with ammo: %1, Target: %2", _ammo, _whohit];

if ((_ammo == "Tenthed_6Rnd_127x40_Cyl_NARQ") || {_ammo == "Tenthed_6Rnd_127x40_Cyl_NARQ_Tracer"} || {_ammo == "Tenthed_B_127x40_NARQ_Ball"}) then {
    diag_log "[Narq] Narq ammo detected.";

    private _oldNarqedUntilTime = _whohit getVariable ["CSW_isNarqedUntil", CBA_missionTime - 1];
    private _newTime = CBA_missionTime + CSW_NARQTIME;
    _whohit setVariable ["CSW_isNarqedUntil", _newTime, true];

    if (_oldNarqedUntilTime >= CBA_missionTime) exitWith {
        private _weap = currentWeapon _whohit;
        if ((_weap != "") && {_weap != "ACE_FakePrimaryWeapon"} && {vehicle _whohit == _whohit} && {_oldNarqedUntilTime < _newTime - 2}) then {
            _whohit removeWeapon _weap;
            if (isTouchingGround _whohit) then {
                private _dir = getDir _whohit;
                private _dropPos = (ASLToAGL getPosASL _whohit) vectorAdd [-cos (_dir - 25) * 1.4, sin (_dir - 25) * 1.4, 0];
                private _holder = createVehicle ["groundweaponHolder", _dropPos, [], 0, "CAN_COLLIDE"];
                _holder addWeaponCargoGlobal [_weap, 1];
                _holder setDir (190 + _dir);
            };
        };
    };

    [_whohit, _shooter, _oldNarqedUntilTime] spawn {
        params ["_whohit", "_shooter", "_oldNarqedUntilTime"];
        private _wasStopped = false;

        if (vehicle _whohit == _whohit) then {
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

            private _weap = currentWeapon _whohit;
            if ((_weap != "") && {_weap != "ACE_FakePrimaryWeapon"}) then {
                _whohit removeWeapon _weap;
                if (isTouchingGround _whohit) then {
                    private _dir = getDir _whohit;
                    private _dropPos = (ASLToAGL getPosASL _whohit) vectorAdd [-cos (_dir - 25) * 1.4, sin (_dir - 25) * 1.4, 0];
                    private _holder = createVehicle ["groundweaponHolder", _dropPos, [], 0, "CAN_COLLIDE"];
                    _holder addWeaponCargoGlobal [_weap, 1];
                    _holder setDir (190 + _dir);
                };
            };

            if (!isNil "ace_medical_fnc_setUnconscious" && {!(_whohit call ace_common_fnc_isZombie)}) then {
                sleep 0.5;
                [_whohit, true, CSW_NARQTIME, true] call ace_medical_fnc_setUnconscious;
            };
        } else {
            if (isNil "ace_medical_fnc_setUnconscious" || {_whohit call ace_common_fnc_isZombie}) then {
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

        [_whohit, _wasStopped] spawn {
            params ["_whohit", "_wasStopped"];
            waitUntil { (_whohit getVariable ["CSW_isNarqedUntil", 0]) <= CBA_missionTime };

            if (_wasStopped) then {
                [_whohit, false] remoteExecCall ["stop", 0];
                [_whohit, false] remoteExecCall ["ace_common_fnc_disableAI", _whohit];
            };

            if (!isNil "ace_medical_fnc_setUnconscious" && {!(_whohit call ace_common_fnc_isZombie)}) then {
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
	diag_log format ["[NARQ] %1 shot %2 with %3 at %4", _shooter, _whohit, _ammo, CBA_missionTime];
};
