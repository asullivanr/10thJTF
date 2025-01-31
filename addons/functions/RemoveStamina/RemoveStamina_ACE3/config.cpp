class CfgPatches
{
	class RemoveStamina_ACE
	{
		name="Remove Stamina - ACE 3";
		units[]={};
		weapons[]={};
		requiredVersion=1.62;
		requiredAddons[]=
		{
			"ace_advanced_fatigue"
		};
	};
};
class ACE_Settings
{
	class ace_advanced_fatigue_enabled
	{
		category="Advanced Fatigue";
		displayName="$STR_ace_advanced_fatigue_Enabled";
		description="$STR_ace_advanced_fatigue_Enabled_Description";
		typeName="BOOL";
		value=0;
	};
	class ace_advanced_fatigue_enableStaminaBar
	{
		category="Advanced Fatigue";
		displayName="$STR_ace_advanced_fatigue_EnableStaminaBar";
		description="$STR_ace_advanced_fatigue_EnableStaminaBar_Description";
		typeName="BOOL";
		value=0;
		isClientSettable=1;
	};
	class ace_advanced_fatigue_performanceFactor
	{
		category="Advanced Fatigue";
		displayName="$STR_ace_advanced_fatigue_PerformanceFactor";
		description="$STR_ace_advanced_fatigue_PerformanceFactor_Description";
		typeName="SCALAR";
		value=0;
	};
	class ace_advanced_fatigue_recoveryFactor
	{
		category="Advanced Fatigue";
		displayName="$STR_ace_advanced_fatigue_RecoveryFactor";
		description="$STR_ace_advanced_fatigue_RecoveryFactor_Description";
		typeName="SCALAR";
		value=0;
	};
	class ace_advanced_fatigue_loadFactor
	{
		category="Advanced Fatigue";
		displayName="$STR_ace_advanced_fatigue_LoadFactor";
		description="$STR_ace_advanced_fatigue_LoadFactor_Description";
		typeName="SCALAR";
		value=0;
	};
	class ace_advanced_fatigue_terrainGradientFactor
	{
		category="Advanced Fatigue";
		displayName="$STR_ace_advanced_fatigue_TerrainGradientFactor";
		description="$STR_ace_advanced_fatigue_TerrainGradientFactor_Description";
		typeName="SCALAR";
		value=0;
	};
};
class CfgVehicles
{
	class ACE_Module;
	class ace_advanced_fatigue_moduleSettings: ACE_Module
	{
		class Arguments
		{
			class Enabled
			{
				defaultValue=0;
			};
			class PerformanceFactor
			{
				defaultValue=0;
			};
			class RecoveryFactor
			{
				defaultValue=0;
			};
			class LoadFactor
			{
				defaultValue=0;
			};
			class TerrainGradientFactor
			{
				defaultValue=0;
			};
		};
	};
};
