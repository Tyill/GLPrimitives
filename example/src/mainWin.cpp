
#include <wx/statline.h>
#include <wx/splitter.h>
#include <wx/valnum.h>

#include "glCanvas.h"
#include "mainWin.h"

using namespace std;

MainWin* mainWin = nullptr;

void statusMess(const std::string& mess){

    mainWin->SetStatusText(mess);
}

MainWin::MainWin(App* app_) :    
    wxFrame(NULL, wxID_ANY, "glPrExample", wxDefaultPosition, wxDefaultSize,
    wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE | wxMAXIMIZE){
     
    app = app_;
    mainWin = this;

    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizerAndFit(mainSizer);

    CreateStatusBar();
    SetStatusText("");

    app->Bind(wxEVT_KEY_DOWN, [this](wxKeyEvent& event){

        event.Skip();
    });

    wxGLAttributes vAttrs;
    vAttrs.PlatformDefaults().Defaults().EndList();

    GLCanvas* glCanvas = new GLCanvas(this, vAttrs);
    glCanvas->SetWindowStyle(wxBORDER_SIMPLE);

   

    mainSizer->Add(glCanvas, wxSizerFlags(1).Expand().Border(wxLEFT | wxRIGHT, 5));
    
    this->Maximize(true);        
}
