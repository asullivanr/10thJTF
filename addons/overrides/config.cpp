class CfgPatches {
    class Tenthed_overrides {
        author = "Akira";
        name   = "10th JTF: Overrides";
        requiredAddons[] = {
            "GX_Blanco_Cartel"
        };
        weapons[] = {
			"TEN_Ballistic_Mask",
			"TEN_B_M_Good",
			"TEN_B_M_Extreme",
			"TEN_B_M_God",
			"TEN_B_M_Officer",
			"TEN_B_M_SL",
			"TEN_B_M_UP",
			"TEN_BC_Carrier_GL_Black",
			"TEN_BC_Carrier_Special_Black",
			"TEN_arifle_CTARS_blk_F",
			"TEN_srifle_DMR_04_F"
        };
        units[]   = {
            "TEN_B_C_Rifleman",
			"TEN_B_C_Medic",
			"TEN_B_C_Engineer",
			"TEN_B_C_MG",
			"TEN_B_C_AT",
			"TEN_B_C_Marksman",
			"TEN_B_C_Officer",
			"TEN_B_C_SL",
			"TEN_B_C_Rifleman_Light",
			"TEN_B_C_Medic_Light",
			"TEN_B_C_Engineer_Light",
			"TEN_B_C_MG_Light",
			"TEN_B_C_AT_Light",
			"TEN_B_C_Marksman_Light",
			"TEN_B_C_Officer_Light",
			"TEN_B_C_SL_Light",
			"TEN_B_C_Rifleman_NVG",
			"TEN_B_C_Medic_NVG",
			"TEN_B_C_Engineer_NVG",
			"TEN_B_C_MG_NVG",
			"TEN_B_C_AT_NVG",
			"TEN_B_C_Marksman_NVG",
			"TEN_B_C_SL_NVG",
			"TEN_B_C_Rifleman_Light_NVG",
			"TEN_B_C_Medic_Light_NVG",
			"TEN_B_C_Engineer_Light_NVG",
			"TEN_B_C_MG_Light_NVG",
			"TEN_B_C_AT_Light_NVG",
			"TEN_B_C_Marksman_Light_NVG",
			"TEN_B_C_SL_Light_NVG",
			"TEN_B_C_Miguel_Blanco",
			"TEN_B_C_Javier_Blanco",
			"TEN_B_C_Diver_Light_NVG",
			"TEN_B_C_Backpack",
			"TEN_B_C_Backpack_Medic",
			"TEN_B_C_Backpack_Engineer",
			"TEN_B_C_Backpack_MG",
			"TEN_B_C_Backpack_AT",
			"TEN_B_C_Offroad_Comms",
			"TEN_B_C_Offroad_Covered",
			"TEN_B_C_Offroad_MG",
			"TEN_B_C_Offroad_AT",
			"TEN_B_C_Offroad_MG_NVG",
			"TEN_B_C_Offroad_AT_NVG",
			"TEN_B_C_Van",
			"TEN_B_C_Quad",
			"TEN_B_C_Helicopter",
			"TEN_B_C_Helicopter_02",
			"TEN_B_C_Plane",
			"TEN_B_C_Static_M2_Raised",
			"TEN_B_C_Static_M2",
			"TEN_B_C_Static_Mortar",
			"TEN_B_C_Boat_01",
			"TEN_B_C_Boat_02",
			"TEN_B_C_Boat_03",
			"TEN_B_C_Drone_01",
			"TEN_B_C_Drone_02",
			"TEN_B_C_Sub_01"
        };
    };
};
class CfgFactionClasses
{
	class TEN_B_C_Faction
	{
		displayName="10thMod - Blanco Cartel";
		author="GanX";
		icon="GX_BLANCO_CARTEL\Textures\Icons\GX_Blanco_Cartel_Icon.paa";
		priority=2;
		side=0;
	};
};
class CfgVehicles
{
    #include "vehicles.hpp"
};
class CfgWeapons
{
    #include "vests.hpp"
};
class CfgGroups
{
    #include "groups.hpp"
};