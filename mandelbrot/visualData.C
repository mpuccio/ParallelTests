#include <TStyle.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <Riostream.h>


void visualData(TString str="data.dat") {
	gStyle->SetPalette(53);
	gStyle->SetOptStat(kFALSE);
	const int size = 1<<10;
	TCanvas *cv = new TCanvas("mdl","Mandelbrot set");
	cv->cd();
	cv->SetLogz();
	TH2F *h = new TH2F("mandelbrot","Mandelbrot set",size,-2,2,size,-2,2);

	ifstream f(str.Data());
	int count=0;
	float x;
	const float step = 4.f/size;
	while ( f>>x ) {
		if (x<=1) x=1;
		//cout << -2+(count/1024)*step << " " <<-2+(count%1024)*step << " " << x << endl;
		h->Fill(-2+(count/size+0.5f)*step,-2+(count%size+0.5f)*step,x);
		count++;
	}
	h->Draw("colz");
}