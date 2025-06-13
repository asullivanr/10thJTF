/*
    File: fn_isAuthorizedPlayer.sqf
    Description: Returns true if the player is an admin or on the allowed UID list.
*/

params [];

private _isAdmin = serverCommandAvailable "#ban";
private _uid = getPlayerUID player;
private _isWhitelisted = (!isNil "Tenthed_allowedUIDs") && {_uid in Tenthed_allowedUIDs};

_isAdmin || _isWhitelisted
