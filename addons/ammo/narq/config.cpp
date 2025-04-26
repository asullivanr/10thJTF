class CfgPatches
{
	class Tenthed_Ammo_Narq
	{
		author="Baseplate";
		name="The Carver Findings";
		addonRootClass="Tenthed_Ammo";
		units[]={};
		weapons[]={};
		magazines[]={};
		ammo[]={};
		requiredVersion=1;
		requiredAddons[]=
		{
			"A3_Data_F_Decade_Loadorder",
			"Tenthed_Ammo"
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class Tenthed_functions_narq
	{
		init="call compile preprocessFileLineNumbers 'z\10thJTF\addons\ammo\narq\XEH_preStart.sqf'; ";
	};
};
class Extended_PreInit_EventHandlers
{
	class Tenthed_functions_narq
	{
		init="call compile preprocessFileLineNumbers 'z\10thJTF\addons\ammo\narq\XEH_preInit.sqf'; ";
	};
};
class Extended_Respawn_EventHandlers
{
	class CAManBase
	{
		class Tenthed_functions_narq
		{
			respawn="_this call CSW_fnc_NarqOnRespawn";
		};
	};
};
class Extended_Hit_EventHandlers
{
	class CAManBase
	{
		Tenthed_Narq="_this call CSW_fnc_NarqOnHit;";
	};
};
