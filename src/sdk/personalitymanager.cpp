/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU Lesser General Public License, version 3
 * http://www.gnu.org/licenses/lgpl-3.0.html
 *
 * $Revision: 12076 $
 * $Id: personalitymanager.cpp 12076 2020-05-12 14:51:47Z pecanh $
 * $HeadURL: svn://svn.code.sf.net/p/codeblocks/code/trunk/src/sdk/personalitymanager.cpp $
 */

#include "sdk_precomp.h"

#ifndef CB_PRECOMP
    #include "manager.h"
    #include "configmanager.h"
    #include <wx/intl.h>
    #include <wx/dir.h>
    #include <wx/filename.h>
#endif

#include <wx/arrstr.h>

#include "personalitymanager.h"

template<> PersonalityManager* Mgr<PersonalityManager>::instance = nullptr;
template<> bool  Mgr<PersonalityManager>::isShutdown = false;

PersonalityManager::PersonalityManager()
{
    PersonalityManager::pers = _T("default");
}

void PersonalityManager::SetPersonality(const wxString& personality, cb_unused bool createIfNotExist)
{
    pers = personality;
}

const wxString PersonalityManager::GetPersonality()
{
    return pers;
}

const wxArrayString PersonalityManager::GetPersonalitiesList()
{
    wxArrayString list, allConf;
    wxDir::GetAllFiles(ConfigManager::GetConfigFolder(), &allConf, _T("*.conf"), wxDIR_FILES);

    for(size_t i = 0; i < allConf.GetCount(); ++i)
    {
        // return only <personality>.conf names, exclude <personality>.some.other.conf
        if (wxFileName(allConf[i]).GetName().Contains(wxT(".cbKeyBinder")))
            continue;
        list.Add(wxFileName(allConf[i]).GetName());
    }

    return list;
}

wxString PersonalityManager::pers;

