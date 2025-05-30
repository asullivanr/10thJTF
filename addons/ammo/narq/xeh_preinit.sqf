diag_log "[Narq] Loading: 10th JTF Functions Narq Preinit";

// Safe ACE function overrides
if (isNil {ace_common_fnc_getDeathAnim}) then {
    ace_common_fnc_getDeathAnim = compileFinal "
        params ['_unit'];
        private _anim = animationState _unit;
        private _cfg = configFile >> 'CfgMovesMaleSdr' >> 'States' >> _anim;

        if (getNumber (_cfg >> 'terminal') == 1) exitWith { _anim };

        private _actionsCfg = configFile >> 'CfgMovesBasic' >> 'Actions' >> getText (_cfg >> 'actions');
        if (vehicle _unit != _unit) then {
            {
                if (getNumber (configFile >> 'CfgMovesMaleSdr' >> 'States' >> _x >> 'terminal') == 1) exitWith { _x };
            } forEach getArray (_cfg >> 'interpolateTo');
        } else {
            private _dieAnim = getText (_actionsCfg >> 'die');
            if (_dieAnim != '') exitWith { _dieAnim };
        };

        'Unconscious'
    ";
};

if (isNil {ace_common_fnc_isZombie}) then {
    ace_common_fnc_isZombie = compileFinal "
        (_this isKindOf 'RyanZombieCivilian_F') || { _this isKindOf 'RyanZombieB_Soldier_base_F' }
    ";
};

if (isNil {ace_common_fnc_disableAI}) then {
    ace_common_fnc_disableAI = compileFinal "
        params [['_unit', objNull], ['_disable', true]];
        if (!local _unit) exitWith {};
        if (!isPlayer _unit) then {
            if (_disable) then {
                {_unit disableAI _x} forEach ['MOVE','TARGET','AUTOTARGET','FSM'];
                _unit disableConversation true;
            } else {
                if (_unit getVariable ['ace_isunconscious', false] && alive _unit) exitWith {};
                {_unit enableAI _x} forEach ['MOVE','TARGET','AUTOTARGET','FSM'];
                _unit disableConversation false;
            };
        };
    ";
};

CSW_fnc_dropWeapon = {
    params ["_unit"];
    private _weap = currentWeapon _unit;
    if (_weap != "" && _weap != "ACE_FakePrimaryWeapon") then {
        _unit removeWeapon _weap;
        if (isTouchingGround _unit) then {
            private _dir = getDir _unit;
            private _dropPos = (ASLToAGL getPosASL _unit) vectorAdd [-cos (_dir - 25) * 1.4, sin (_dir - 25) * 1.4, 0];
            private _holder = createVehicle ["groundweaponHolder", _dropPos, [], 0, "CAN_COLLIDE"];
            _holder addWeaponCargoGlobal [_weap, 1];
            _holder setDir (190 + _dir);
        };
    };
};

// Compile main narq functions
CSW_fnc_NarqOnHit = compileFinal preprocessFileLineNumbers "\z\10thJTF\addons\ammo\Narq\functions\fnc_NarqOnHit.sqf";
CSW_fnc_NarqOnRespawn = compileFinal preprocessFileLineNumbers "\z\10thJTF\addons\ammo\Narq\functions\fnc_NarqOnRespawn.sqf";

diag_log "[Narq] Done Loading: 10th JTF Functions Narq Preinit";
