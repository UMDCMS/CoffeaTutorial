// root dummy_nanoevent.cc

#include "TFile.h"
#include "TRandom.h"
#include "TTree.h"

int
sgn( int x )
{
  return x > 0 ?  1 :
         x < 0 ? -1 :
         0;
}

void
dummy_nanoevent()
{
  UInt_t run, event, luminosityBlock;
  UInt_t nMuon;
  Float_t Muon_pt[9999];
  Float_t Muon_eta[9999];
  Float_t Muon_phi[9999];
  Float_t Muon_mass[9999];
  Int_t Muon_charge[9999];
  Int_t Muon_flag[9999];
  Float_t Muon_dxy[9999];
  Float_t Muon_dxyErr[9999];
  Float_t Muon_dz[9999];
  Float_t Muon_dzErr[9999];

  std::vector<float> Electron_pt;
  std::vector<float> Electron_eta;
  std::vector<float> Electron_phi;
  std::vector<float> Electron_dxy;
  std::vector<float> Electron_dxyErr;
  std::vector<float> Electron_dz;
  std::vector<float> Electron_dzErr;
  std::vector<float> Electron_mass;
  std::vector<int> Electron_flag;
  std::vector<int> Electron_charge;

  std::vector<double> Jets_Pt;
  std::vector<double> Jets_Eta;
  std::vector<double> Jets_Phi;
  std::vector<double> Jets_E;
  std::vector<double> Jets_ID;
  std::vector<int> Jets_SubjetsCounts;
  std::vector<double> Jets_subjet_Pt;
  std::vector<double> Jets_subjet_Eta;
  std::vector<double> Jets_subjet_Phi;
  std::vector<double> Jets_subjet_E;

  TFile* Tfile = Tfile = TFile::Open( "dummy_nanoevents.root", "RECREATE" );
  TTree* ttree = new TTree( "Events", "" );

  ttree->Branch( "run",                &run,             "run/I" );
  ttree->Branch( "luminosityBlock",    &luminosityBlock, "luminosityBlock/I" );
  ttree->Branch( "event",              &event,           "event/I" );

  ttree->Branch( "nMuon",              &nMuon,           "nMuon/i" );
  ttree->Branch( "Muon_pt",            &Muon_pt,         "Muon_pt[nMuon]/F" );
  ttree->Branch( "Muon_eta",           &Muon_eta,        "Muon_eta[nMuon]/F" );
  ttree->Branch( "Muon_phi",           &Muon_phi,        "Muon_phi[nMuon]/F" );
  ttree->Branch( "Muon_mass",          &Muon_mass,       "Muon_mass[nMuon]/F" );
  ttree->Branch( "Muon_charge",        &Muon_charge,     "Muon_charge[nMuon]/I" );
  ttree->Branch( "Muon_flag",          &Muon_flag,       "Muon_flag[nMuon]/F" );
  ttree->Branch( "Muon_dxy",           &Muon_dxy,        "Muon_dxy[nMuon]/F" );
  ttree->Branch( "Muon_dxyErr",        &Muon_dxyErr,     "Muon_dxyErr[nMuon]/F" );
  ttree->Branch( "Muon_dz",            &Muon_dz,         "Muon_dz[nMuon]/F" );
  ttree->Branch( "Muon_dzErr",         &Muon_dzErr,      "Muon_dzErr[nMuon]/F" );

  ttree->Branch( "Electron_pt",        &Electron_pt );
  ttree->Branch( "Electron_eta",       &Electron_eta );
  ttree->Branch( "Electron_phi",       &Electron_phi );
  ttree->Branch( "Electron_mass",      &Electron_mass );
  ttree->Branch( "Electron_charge",    &Electron_charge );
  ttree->Branch( "Electron_flag",      &Electron_flag );
  ttree->Branch( "Electron_dxy",       &Electron_dxy );
  ttree->Branch( "Electron_dxyErr",    &Electron_dxyErr );
  ttree->Branch( "Electron_dz",        &Electron_dz );
  ttree->Branch( "Electron_dzErr",     &Electron_dzErr );

  ttree->Branch( "Jet_pt",            &Jets_Pt );
  ttree->Branch( "Jet_eta",           &Jets_Eta );
  ttree->Branch( "Jet_phi",           &Jets_Phi );
  ttree->Branch( "Jet_energy",             &Jets_E );
  ttree->Branch( "Jet_ID",            &Jets_ID );
  ttree->Branch( "Jet_SubjetsCounts", &Jets_SubjetsCounts );
  ttree->Branch( "Subjet_pt",     &Jets_subjet_Pt );
  ttree->Branch( "Subjet_eta",    &Jets_subjet_Eta );
  ttree->Branch( "Subjet_phi",    &Jets_subjet_Phi );
  ttree->Branch( "Subjet_energy",      &Jets_subjet_E );

  for( Int_t ev = 0; ev < 100; ev++ ){
    run             = 1;
    event           = ev;
    luminosityBlock = 1000 * ev;
    Int_t nmu  = Int_t( 5 * gRandom->Rndm() + 2 );
    Int_t nele = Int_t( 5 * gRandom->Rndm() + 2 );
    Int_t njet = Int_t( 3 * gRandom->Rndm() + 1 );
    nMuon = nmu;

    if( nmu < 0 ){
      nmu = 0;
    }

    for( Int_t im = 0; im < nmu; im++ ){
      Muon_pt[im]     = gRandom->Gaus( 50, 10 );
      Muon_eta[im]    = gRandom->Rndm();
      Muon_phi[im]    = gRandom->Rndm();
      Muon_mass[im]   = 0.105;
      Muon_charge[im] = sgn( gRandom->Rndm() - 0.5 );
      Muon_flag[im]   = int( 5*gRandom->Rndm() );
      Muon_dxy[im]    = gRandom->Rndm();
      Muon_dxyErr[im] = gRandom->Rndm() / 10;
      Muon_dz[im]     = gRandom->Rndm();
      Muon_dzErr[im]  = gRandom->Rndm() / 10;
    }

    if( nele < 0 ){
      nele = 0;
    }
    Electron_pt.clear();
    Electron_eta.clear();
    Electron_phi.clear();
    Electron_mass.clear();
    Electron_charge.clear();
    Electron_flag.clear();
    Electron_dxy.clear();
    Electron_dxyErr.clear();
    Electron_dz.clear();
    Electron_dzErr.clear();

    for( Int_t in = 0; in < nele; in++ ){
      Electron_pt.push_back( gRandom->Gaus( 50, 10 ) );
      Electron_eta.push_back( gRandom->Rndm() );
      Electron_phi.push_back( gRandom->Rndm() );
      Electron_mass.push_back( 0.000510 );
      Electron_charge.push_back( sgn( gRandom->Rndm() - 0.5 ) );
      Electron_flag.push_back( int(5*gRandom->Rndm() ) );
      Electron_dxy.push_back( gRandom->Rndm() );
      Electron_dxyErr.push_back( gRandom->Rndm() / 10 );
      Electron_dz.push_back( gRandom->Rndm() );
      Electron_dzErr.push_back( gRandom->Rndm() / 10 );
    }

    Jets_Pt.clear();
    Jets_Eta.clear();
    Jets_Phi.clear();
    Jets_E.clear();
    Jets_ID.clear();
    Jets_SubjetsCounts.clear();
    Jets_subjet_Pt.clear();
    Jets_subjet_Eta.clear();
    Jets_subjet_Phi.clear();
    Jets_subjet_E.clear();

    for( int i = 0; i < njet; i++ ){
      Jets_Pt.push_back( 10 * gRandom->Rndm() );
      Jets_Eta.push_back( gRandom->Rndm() );
      Jets_Phi.push_back( gRandom->Rndm() );
      Jets_E.push_back( gRandom->Gaus( 50, 10 ) );
      Jets_ID.push_back( int( 7*gRandom->Rndm() ) );
      // subjets
      Int_t jets_sub = Int_t( 3 * gRandom->Rndm() );
      Jets_SubjetsCounts.push_back( jets_sub );

      for( int i = 0; i < jets_sub; i++ ){
        Jets_subjet_Pt.push_back( 10 * gRandom->Rndm() );
        Jets_subjet_Eta.push_back( gRandom->Rndm() );
        Jets_subjet_Phi.push_back( gRandom->Rndm() );
        Jets_subjet_E.push_back( gRandom->Gaus( 25, 10 ) );
      }
    }

    ttree->Fill();
  }

  ttree->Write();
}
