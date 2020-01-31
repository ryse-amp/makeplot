#include "TFile.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include <iostream>
#include <TLegend.h>

void makePlot(){
  
  TFile *f=TFile::Open("physval-21.3test.root","READ");

cout<<"1. Open a Root File"<<endl;

  TCanvas *c = new TCanvas("c","TProfile Histogram",1500,1500);
  c->Draw();
cout<<"2. Create the canvas"<<endl;
  TProfile *h;
cout<<"3. set h pointer as TProfile class"<<endl;
  std::vector<TString>Hist=
    {
      "tau25_idperf_tracktwoMVA",
      "tau25_idperf_tracktwoRNN",
      "tau25_idperf_tracktwoMVABDT",
      
    };
cout<<"4. Set the vector-chain"<<endl;
  for (int i=0; i<Hist.size();i++){

cout<<"5. Enter in FOR estructure"<<endl; 
      h=(TProfile*)f->Get("run_1/HLT/TauMon/Expert/"+Hist[i]+"/TurnOnCurves/RecoEfficiency/TProfRecoL1EtaEfficiency");
cout<<"6. Made the copy of the TProfile histogram"<<endl;
   
      h->SetLineColor(i+2);
cout<<"7. Set line colour of the histogram with i="<< i <<endl;

   auto legend = new TLegend(0.99,0.5,0.75,0.4);
   legend->SetHeader("The Legend Title","C");
   legend->AddEntry("h","Red tau25_idperf_tracktwoMVA","l");
   legend->AddEntry("h","Green tau25_idperf_tracktwoRNN","l");
   legend->AddEntry("h","Blue tau25_idperf_tracktwoMVABDT","l");
   legend->Draw();
cout<<"8. Set the legend of the histogram"<<endl;

      if (i==1){
cout<<"9. Enter inside the if with i="<< i <<endl;   
      h->Draw("same");
cout<<"10. Draw the histogram"<<endl; 
      gDirectory->cd("../../../");
cout<<"11. Come back three directories"<<endl;
      }
      
else if (i==2){
      cout<<"12. Enter inside the  else if with i="<< i <<endl;   
     
      h->Draw("same");
      cout<<"13. Draw the histogram"<<endl; 
      gDirectory->cd("../../../");
      cout<<"14. Come back three directories"<<endl;
      gStyle->SetOptStat(0);
      cout<<"15. Removing statics box"<<endl;
      }
      else {
      cout<<"16. Enter to else with i="<< i <<endl;
      
      cout<<"17. Set the color of the line number="<< i+2 <<endl;
      h->Draw();
      
      cout<<"18. Draw in else part"<<endl; 
      gDirectory->cd("../../../");
      cout<<"19. Come back three directories"<<endl;
      
    }

      
  } 



}
