//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef HUD_CHAT_H
#define HUD_CHAT_H
#ifdef _WIN32
#pragma once
#endif

#include <hud_basechat.h>
#include "steam/steam_api.h"

class CHudChat : public CBaseHudChat
{
    DECLARE_CLASS_SIMPLE(CHudChat, CBaseHudChat);

public:
    CHudChat(const char *pElementName);

    virtual void	Init(void);

    void			MsgFunc_SayText(bf_read &msg);
    void			MsgFunc_SayText2(bf_read &msg);
    void			MsgFunc_TextMsg(bf_read &msg);
    void MsgFunc_SpecUpdateMsg(bf_read &msg);
    void MsgFunc_LobbyUpdateMsg(bf_read &msg);

    // MOM_TODO: Move these elsewhere. Maybe in clientmode? Something that has access to multiple UI components.
    STEAM_CALLBACK(CHudChat, OnLobbyMessage, LobbyChatMsg_t);
    STEAM_CALLBACK(CHudChat, OnLobbyDataUpdate, LobbyDataUpdate_t);
    STEAM_CALLBACK(CHudChat, OnLobbyEnter, LobbyEnter_t);
    STEAM_CALLBACK(CHudChat, OnLobbyKicked, LobbyKicked_t);

    void StartMessageMode(int) OVERRIDE;
    void StopMessageMode() OVERRIDE;

    void Paint() OVERRIDE;
    void OnThink() OVERRIDE;

private:
    CUtlVector<CSteamID> m_vTypingMembers;
    CUtlVector<CSteamID> m_vMomentumOfficers;
    uint64 m_uiLobbyId;
    vgui::HFont m_hfInfoTextFont;
    bool m_bTyping;
    bool m_bIsVisible;
};

#endif	//HUD_CHAT_H