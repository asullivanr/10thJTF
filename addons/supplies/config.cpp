class CfgPatches {
    class Tenthed_Supplies {
        author = "Akira";
        name = "10th JTF: Supplies";
        requiredAddons[] = {};
        weapons[] = {};
        units[] = {};
    };
};
class CfgVehicles {
    class I_E_CargoNet_01_ammo_F;
    class Tenthed_Resupply_Weapons : I_E_CargoNet_01_ammo_F {
        displayName = "[10th] Weapons Resupply";
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        init = "this addAction ['Weapons Resupply', {}]";
        class Cargo {
            items[] = {
                {"hlc_rifle_M4_grip2", 30},
                {"hlc_m249_pip2_30Rnd", 15},
                {"rhs_weap_M320", 20},
                {"BWA3_P2A1", 30},
                {"rhs_weap_m14ebrri", 15},
                {"rhs_weap_maaws", 20},
                {"rhs_weap_M136", 40},
                {"rhs_weap_fim92", 20},

                {"hlc_200rnd_556x45_B_SAW", 50},
                {"hlc_30rnd_556x45_EPR", 180},
                {"1Rnd_Smoke_Grenade_shell", 20},
                {"1Rnd_SmokeRed_Grenade_shell", 20},
                {"1Rnd_SmokeGreen_Grenade_shell", 20},
                {"1Rnd_SmokeYellow_Grenade_shell", 20},
                {"1Rnd_SmokePurple_Grenade_shell", 20},
                {"1Rnd_SmokeBlue_Grenade_shell", 20},
                {"1Rnd_SmokeOrange_Grenade_shell", 20},
                {"ACE_HuntIR_M203", 50},
                {"rhs_mag_M441_HE", 30},
                {"rhs_mag_M433_HEDP", 30},
                {"rhs_mag_M397_HET", 30},
                {"rhs_mag_m576", 20},
                {"rhs_mag_m4009", 20},
                {"rhs_mag_M583A1_white", 20},
                {"rhs_mag_m661_green", 20},
                {"rhs_mag_m662_red", 20},
                {"rhs_mag_M585_white_cluster", 20},
                {"rhs_mag_M663_green_cluster", 20},
                {"rhs_mag_M664_red_cluster", 20},
                {"ACE_40mm_Flare_white", 20},
                {"ACE_40mm_Flare_red", 20},
                {"ACE_40mm_Flare_green", 20},
                {"ACE_40mm_Flare_ir", 20},
                {"PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade_40mm", 20},
                {"PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade_40mm_3GL", 20},
                {"BWA3_1Rnd_Flare_Illum", 20},
                {"BWA3_1Rnd_Flare_Singlestar_White", 20},
                {"BWA3_1Rnd_Flare_Singlestar_Green", 20},
                {"BWA3_1Rnd_Flare_Singlestar_Red", 20},
                {"BWA3_1Rnd_Flare_Multistar_White", 20},
                {"BWA3_1Rnd_Flare_Multistar_Green", 20},
                {"BWA3_1Rnd_Flare_Multistar_Red", 20},
                {"rhsusf_20Rnd_762x51_m993_Mag", 70},
                {"MRAWS_HEAT_F", 100},
                {"rhs_fim92_mag", 100}
            };
        };
    };

    class Tenthed_Restricted_Arsenal : I_E_CargoNet_01_ammo_F {
        displayName = "[10th] Arsenal";
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        init = "[this, true] call Tenthed_fnc_Arsenal";
        class Cargo {
            items[] = { };
        };
    };
};