/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 *
 * $Revision: 12190 $
 * $Id: projectmanagerui.h 12190 2020-07-29 21:09:40Z fuscated $
 * $HeadURL: svn://svn.code.sf.net/p/codeblocks/code/trunk/src/src/projectmanagerui.h $
 */

#include "projectmanager.h"

class cbProject;
class cbAuiNotebook;
class FilesGroupsAndMasks;
class wxAuiNotebookEvent;

class ProjectManagerUI : public wxEvtHandler, public cbProjectManagerUI
{
    public:
        ProjectManagerUI();
        ~ProjectManagerUI();

        cbAuiNotebook* GetNotebook() override { return m_pNotebook; }

        /** Retrieve a pointer to the project manager's tree (GUI).
          * @return A pointer to a wxTreeCtrl window.
          */
        cbTreeCtrl* GetTree() override { return m_pTree; }

        wxTreeItemId GetTreeSelection() override;

        void RebuildTree() override;
        void FreezeTree() override;
        void UnfreezeTree(bool force = false) override;


        void UpdateActiveProject(cbProject* oldProject, cbProject* newProject,
                                 bool refresh) override;
        void RemoveProject(cbProject* project) override;
        void BeginLoadingWorkspace() override;
        void CloseWorkspace() override;
        void FinishLoadingProject(cbProject* project, bool newAddition,
                                  cb_unused FilesGroupsAndMasks* fgam) override;
        void FinishLoadingWorkspace(cbProject* activeProject,
                                    const wxString &workspaceTitle) override;

        void ShowFileInTree(ProjectFile &projectFile) override;

        void CreateMenu(wxMenuBar* menuBar);

        bool QueryCloseAllProjects() override;
        bool QueryCloseProject(cbProject* project, bool dontsavefiles) override;
        bool QueryCloseWorkspace() override;

        int AskForBuildTargetIndex(cbProject* project) override;
        wxArrayInt AskForMultiBuildTargetIndex(cbProject* project) override;
        void ConfigureProjectDependencies(cbProject* base, wxWindow *parent) override;
        void CheckForExternallyModifiedProjects();

    private:
        void InitPane();
        void SwitchToProjectsPage() override;
        void ShowMenu(wxTreeItemId id, const wxPoint& pt);
        void CreateMenuTreeProps(wxMenu* menu, bool popup);

        void DoOpenFile(ProjectFile* pf, const wxString& filename);
        void DoOpenSelectedFile();
        void RemoveFilesRecursively(wxTreeItemId& sel_id);
        void OpenFilesRecursively(wxTreeItemId& sel_id);
    private:

        void OnTabContextMenu(wxAuiNotebookEvent& event);
        void OnTabPosition(wxCommandEvent& event);
        void OnProjectFileActivated(wxTreeEvent& event);
        void OnExecParameters(wxCommandEvent& event);
        void OnTreeItemRightClick(wxTreeEvent& event);
        void OnTreeBeginDrag(wxTreeEvent& event);
        void OnTreeEndDrag(wxTreeEvent& event);
        void OnRightClick(wxCommandEvent& event);
        void OnRenameWorkspace(wxCommandEvent& event);
        void OnSaveWorkspace(wxCommandEvent& event);
        void OnSaveAsWorkspace(wxCommandEvent& event);
        void OnCloseWorkspace(wxCommandEvent& event);
        void OnSetActiveProject(wxCommandEvent& event);
        void OnAddFilesToProjectRecursively(wxCommandEvent& event);
        void OnAddFileToProject(wxCommandEvent& event);
        void OnRemoveFileFromProject(wxCommandEvent& event);
        void OnRenameFile(wxCommandEvent& event);
        void OnSaveProject(wxCommandEvent& event);
        void OnCloseProject(wxCommandEvent& event);
        void OnSaveFile(wxCommandEvent& event);
        void OnCloseFile(wxCommandEvent& event);
        void OnOpenFile(wxCommandEvent& event);
        void OnOpenFolderFiles(wxCommandEvent& event);
        void OnOpenWith(wxCommandEvent& event);
        void OnProperties(wxCommandEvent& event);
        void OnFileOptions(wxCommandEvent &event);
        void OnNotes(wxCommandEvent& event);
        void OnGotoFile(wxCommandEvent& event);
        void OnViewCategorize(wxCommandEvent& event);
        void OnViewUseFolders(wxCommandEvent& event);
        void OnViewHideFolderName(wxCommandEvent& event);
        void OnViewFileMasks(wxCommandEvent& event);
        void OnFindFile(wxCommandEvent& event);
        wxArrayString ListNodes(wxTreeItemId node) const;
        void OnBeginEditNode(wxTreeEvent& event);
        void OnEndEditNode(wxTreeEvent& event);
        void OnAddVirtualFolder(wxCommandEvent& event);
        void OnDeleteVirtualFolder(wxCommandEvent& event);
        void OnRenameVirtualFolder(wxCommandEvent& event);
        void OnUpdateUI(wxUpdateUIEvent& event);
        void OnIdle(wxIdleEvent& event);
        void OnKeyDown(wxTreeEvent& event);


        /** Move a project up in the project manager tree. This effectively
          * re-orders the projects build order.
          * @param project The project to move up.
          * @param warpAround If true and the project is at the top of the list order,
          * then it wraps and goes to the bottom of the list.
          */
        void MoveProjectUp(cbProject* project, bool warpAround = false);
        /** Move a project down in the project manager tree. This effectively
          * re-orders the projects build order.
          * @param project The project to move down.
          * @param warpAround If true and the project is at the bottom of the list order,
          * then it wraps and goes to the top of the list.
          */
        void MoveProjectDown(cbProject* project, bool warpAround = false);

        /** (Re)build the project tree.
          * @param tree The wxTreeCtrl to use.
          * @param root The tree item to use as root. The project is built as a child of this item.
          * @param ptvs The visual style of the project tree
          * @param fgam If not NULL, use these file groups and masks for virtual folders.
          */
        void BuildProjectTree(cbProject* project, cbTreeCtrl* tree, const wxTreeItemId& root,
                              int ptvs, FilesGroupsAndMasks* fgam);

    private:
        cbAuiNotebook*       m_pNotebook;
        cbTreeCtrl*          m_pTree;
        wxTreeItemId         m_TreeRoot;
        std::unique_ptr<wxImageList> m_pImages;
        int                  m_TreeVisualState;
        int                  m_TreeFreezeCounter;
        wxArrayTreeItemIds   m_DraggingSelection;
        wxTreeItemId         m_RightClickItem;
        bool                 m_isCheckingForExternallyModifiedProjects;

    private:
        DECLARE_EVENT_TABLE()
};

/// Almost empty implementation used in batch mode.
class BatchProjectManagerUI : public cbProjectManagerUI
{
    public:
        cbAuiNotebook* GetNotebook() override { return nullptr; }
        cbTreeCtrl* GetTree() override { return nullptr; }
        void RebuildTree() override {}
        void FreezeTree() override {}
        void UnfreezeTree(cb_unused bool force = false) override {}
        wxTreeItemId GetTreeSelection() override { return wxTreeItemId(); }

        void ShowFileInTree(cb_unused ProjectFile &projectFile) override {}

        void UpdateActiveProject(cb_unused cbProject *oldProject, cb_unused cbProject *newProject,
                                 cb_unused bool refresh) override
        {
        }

        void RemoveProject(cb_unused cbProject *project) override {}
        void BeginLoadingWorkspace() override {}
        void CloseWorkspace() override {}
        void FinishLoadingProject(cb_unused cbProject *project, cb_unused bool newAddition,
                                  cb_unused FilesGroupsAndMasks* fileGroups) override
        {
        }
        void FinishLoadingWorkspace(cb_unused cbProject *activeProject,
                                    cb_unused const wxString &workspaceTitle) override
        {
        }
        bool QueryCloseAllProjects() override { return true; }
        bool QueryCloseProject(cb_unused cbProject *proj,
                               cb_unused bool dontsavefiles = false) override
        {
            return true;
        }
        bool QueryCloseWorkspace() override { return true; }

        int AskForBuildTargetIndex(cb_unused cbProject* project = nullptr) override { return -1; }
        wxArrayInt AskForMultiBuildTargetIndex(cb_unused cbProject* project = nullptr) override
        {
            return wxArrayInt();
        }
        void ConfigureProjectDependencies(cb_unused cbProject* base,
                                          cb_unused wxWindow *parent) override {}
        void SwitchToProjectsPage() override {}
};
