#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Eczane{
	
private:
	
	int eczn_id;
    string eczn_isim;
    string eczn_adres;
    
public:
	
    Eczane(){  //default ctor
		
		eczn_id=0;
		eczn_isim="-";
		eczn_adres="-";
	}
	
	
	Eczane(int no, string isim, string adres){  //ctor with arguments
		
		eczn_id=no;
		eczn_isim=isim;
		eczn_adres=adres;
	}
	
	
	void eczn_liste_olustur(Eczane a[],int size);
	void eczn_bilgiYazdir();
    friend void eczn_goster(string name);
	
	
//----------------------------------------------------------------------------------------------------------

	
	void set_eczn_id(){
		cout << "Eczane id'sini giriniz: ";
		cin >> eczn_id;
	}
	
	int get_eczn_id(){
		
		return eczn_id;
	}
	
	
	
	
	void set_eczn_isim(){
		cout << "\nEczane ismini giriniz: ";
		cin >> eczn_isim;
	}
	
	string get_eczn_isim(){
		
		return eczn_isim;
	}
	
	
	
	
	void set_eczn_adres(){
		cout << "Eczane adresini giriniz: ";
		cin >> eczn_adres;
	}
	
	string get_eczn_adres(){
		
		return eczn_adres;
	}
	
//--------------------------------------------------------------------------------------------------------
	
	
};



void Eczane::eczn_liste_olustur(Eczane a[],int size){
	
for(int i=0; i<size; i++){

    a[i].set_eczn_isim();
	a[i].set_eczn_id();
	a[i].set_eczn_adres();
  }
}




void Eczane::eczn_bilgiYazdir(){
	cout<<eczn_isim<<"\t"<<eczn_id<<"\t"<<eczn_adres<<endl;
}


void eczn_goster(string name){ //friend fonksiyon
	Eczane E;
	ifstream indosya;
	indosya.open("eczane_listesi.dat",ios::in);
	while(! indosya.eof()){
		
		indosya>>E.eczn_isim;
		indosya>>E.eczn_id;
		indosya>>E.eczn_adres;
		
		if(E.eczn_isim == name){
			E.eczn_bilgiYazdir();
		}	
		
    }
}
	
	




void eczn_listele(){
	ifstream inFile;
	inFile.open("eczane_listesi.dat");
	for (string line; getline(inFile, line); ){
        cout << line << '\n';
    }
	
}




void eczn_ait_ilac_listesi(int id){
	
	ifstream inDosya;
	inDosya.open("ilac_listesi"+to_string(id)+".dat");
	for (string line; getline(inDosya, line); ){
        cout << line << '\n';
    }
}


//**************************************** İLAÇ SINIFI*******************************************************************************

class Ilac{
	
private:
	int ilac_id;
	int ilac_sayisi;
	double ilac_fiyati;
	string ilac_isim;
	
public:
	
	Ilac(){  //default ctor
		
		ilac_id=0;
		ilac_sayisi=0;
		ilac_fiyati=0.0;
		ilac_isim="-";
	}
	
	Ilac(int numa, int i_s, double i_f, string i_i){  //ctor with arguments
		
		ilac_id=numa;
		ilac_sayisi=i_s;
		ilac_fiyati=i_f;
		ilac_isim=i_i;
		
	}
	
	void ilac_bilgiYazdir();
	void ilac_liste_olustur(Ilac b[],int ebat);
    friend void ilac_ara(string ilac);
	
	
	
	void set_ilac_id(){
		cout << "Ilac id'sini giriniz: ";
		cin >> ilac_id;
	}
	
	int get_ilac_id(){
		
		return ilac_id;
	}
	
	
	
	
	void set_ilac_sayisi(){
		cout << "Ilac sayisini giriniz: ";
		cin >> ilac_sayisi;
	}
	
	int get_ilac_sayisi(){
		
		return ilac_sayisi;
	}
	
	
	
	
	void set_ilac_fiyati(){
		cout << "Ilac fiyatini giriniz: ";
		cin >> ilac_fiyati;
	}
	
	double get_ilac_fiyati(){
		
		return ilac_fiyati;
	}
	
	void set_ilac_isim(){
		cout << "\nIlac ismini giriniz: ";
		cin >> ilac_isim;
	}
	
	string get_ilac_isim(){
		
		return ilac_isim;
	}
	
	
};


void Ilac::ilac_liste_olustur(Ilac b[],int ebat){
	
for(int i=0; i<ebat; i++){

    b[i].set_ilac_isim();
	b[i].set_ilac_id();
	b[i].set_ilac_fiyati();
	b[i].set_ilac_sayisi();
  }
}




void Ilac::ilac_bilgiYazdir(){
	cout<<ilac_isim<<"\t"<<ilac_id<<"\t"<<ilac_fiyati<<"\t"<<ilac_sayisi;
}



void ilac_ara(string ilac){ //friend fonksiyon
    Ilac a;
	ifstream inOku[10];
	for(int k=0; k<10; k++){
		inOku[k].open("ilac_listesi"+to_string(k+1)+".dat",ios::in);
		
		if (!inOku[k]){
		    cout<<" ";
	    }                      //bazi dosyalari 2 kere okuyor.nedeni ?
	    else{
		    while(! inOku[k].eof()){
			
			    inOku[k]>>a.ilac_isim;
			    inOku[k]>>a.ilac_id;
			    inOku[k]>>a.ilac_fiyati;
			    inOku[k]>>a.ilac_sayisi;
			   
	            if(a.ilac_isim == ilac){
			    	cout<<"\n";
			    	a.ilac_bilgiYazdir();
			        cout<<"\tEczaneNo:"+to_string(k+1)+" ";
			        
			    }
				
			}
		    inOku[k].close();
	    }
		    
	}
			
}





int main(){
	
	Eczane e[10], e_yeni[10];
	Ilac il[10], il_yeni[10], med[10];
	

    cout<<"\n\t\t\t\t--------------------\n";
	cout<<"\t\t\t\tECZANE TAKIP SISTEMI";
	cout<<"\n\t\t\t\t--------------------\n"<<endl;
	
	
	int secim, sifre, i, j, size, boyut, ebat, sayi, tane, miktar;
	int sec, choose, ecz_no;
	
	
	fstream dosya; //ECZANE LISTESI
	fstream file[10]; //HER ECZANEYE AIT ILAC LISTELERI

	
	cout<<"Yonetim = 1 , Musteri= 2:\n";
	cin>>secim;
	
	if(secim==1){
		cout<<"\nYONETIM\n";
		cout<<"Erisim sifresini giriniz:";
		cin>>sifre;
		if(sifre==345){
			cout<<"Giris yapildi.";
			
			cout<<"\n\nEczane listesi ve ilaclarini olusturmak icin: 1\nYeni eczane ve ilac listesini eklemek icin: 2\nIstediginiz bir eczaneye ilac eklemek icin: 3\nIlac duzenlemek icin: 4\nBitirmek icin: 5"<<endl;
			cin>>sec;
			
		
			while(sec != 5){
	
	          switch(sec){
		
	   	        case 1:{
					
			        cout<<"Kayit edeceginiz eczane sayisini giriniz: ";
				    cin>>size;
				
				    e[i].eczn_liste_olustur(e,size);
				    //cout<<"\n***************** LISTE ****************"<<endl;
				    dosya.open("eczane_listesi.dat",ios::out | ios::in | ios::app);
				    for(int i=0; i<size; i++){
					    cout<<"\n"<<e[i].get_eczn_isim()<<" Eczanesi\t\tNo:"<<e[i].get_eczn_id()<<"\t\tAdres:"<<e[i].get_eczn_adres()<<endl;
						dosya<<"\n"<<e[i].get_eczn_isim()<<"    "<<e[i].get_eczn_id()<<"    "<<e[i].get_eczn_adres()<<endl;  
					}
					cout<<"\nDOSYAYA YAZILDI."<<endl;
					
					
		            for(int i=0; i<size; i++){
		            	
					  cout<<"\n"<<i+1<<". Eczane icin";
		              cout<<" kayit edeceginiz ilac sayisini giriniz: ";
	                  cin>>ebat;
	                  
				      il[j].ilac_liste_olustur(il,ebat);
				    
                      cout<<"\n***************** LISTE ****************"<<endl;
				    
	                  file[i].open("ilac_listesi"+to_string(i+1)+".dat",ios::out | ios::in | ios::app);
				    
	                  for(int j=0; j<ebat; j++){
					   
	                     cout<<"\nIsim:"<<il[j].get_ilac_isim()<<"\t\tNo:"<<il[j].get_ilac_id()<<"\t\tFiyat:"<<il[j].get_ilac_fiyati()<<"\t\tAdet:"<<il[j].get_ilac_sayisi()<<endl;
	                     file[i]<<"\n"<<il[j].get_ilac_isim()<<"    "<<il[j].get_ilac_id()<<"    "<<il[j].get_ilac_fiyati()<<"    "<<il[j].get_ilac_sayisi()<<endl;
					  }
                      cout<<"\nDOSYAYA YAZILDI."<<endl;
                      file[i].close();
                    }
					
                    cout<<"\n\nEczane listesi ve ilaclarini olusturmak icin: 1\nYeni eczane ve ilac listesini eklemek icin: 2\nIstediginiz bir eczaneye ilac eklemek icin: 3\nIlac duzenlemek icin: 4\nBitirmek icin: 5"<<endl;
			        cin>>sec;    
			        break;
			    }
		        case 2:{
					
		        	cout<<"\nEkleyeceginiz eczane sayisini giriniz: ";
		        	cin>>boyut;
		        	
		        	e_yeni[i].eczn_liste_olustur(e_yeni,boyut);
		
				    cout<<"\n***************** EKLENENLER ****************"<<endl;
				    dosya.open("eczane_listesi.dat",ios::out | ios::in | ios::app);
		            for(int i=0; i<boyut; i++){
					   cout<<"\n"<<e_yeni[i].get_eczn_isim()<<" Eczanesi\t\tNo:"<<e_yeni[i].get_eczn_id()<<"\t\tAdres:"<<e_yeni[i].get_eczn_adres()<<endl;
					   dosya<<"\n"<<e_yeni[i].get_eczn_isim()<<"    "<<e_yeni[i].get_eczn_id()<<"    "<<e_yeni[i].get_eczn_adres()<<endl;
					}
                    cout<<"\nDOSYAYA EKLEME YAPILDI.\n";
                    dosya.close();
                    
                    for(int i=0; i<boyut; i++){
		            	
		              cout<<"Eczane icin kayit edeceginiz ilac sayisini giriniz: ";
	                  cin>>tane;
	                  
				      il[j].ilac_liste_olustur(il,tane);
				    
                      cout<<"\n***************** LISTE ****************"<<endl;
                      
				      int b=3;//kayitli 3 eczn oldugu ve 1 eklemeyle 4.ilac listesi olusturulacaği varsayilmistir.
	                  file[b].open("ilac_listesi"+to_string(b+1)+".dat",ios::out | ios::in | ios::app);
				    
	                  for(int j=0; j<tane; j++){
					   
	                     cout<<"\nIsim:"<<il[j].get_ilac_isim()<<"\t\tNo:"<<il[j].get_ilac_id()<<"\t\tFiyat:"<<il[j].get_ilac_fiyati()<<"\t\tAdet:"<<il[j].get_ilac_sayisi()<<endl;
	                     file[b]<<"\n"<<il[j].get_ilac_isim()<<"    "<<il[j].get_ilac_id()<<"    "<<il[j].get_ilac_fiyati()<<"    "<<il[j].get_ilac_sayisi()<<endl;
	                     
					  }
                      cout<<"\nDOSYAYA EKLEME YAPILDI."<<endl;
                      file[b].close();
                      
                    }
                    
			        cout<<"\n\nEczane listesi ve ilaclarini olusturmak icin: 1\nYeni eczane ve ilac listesini eklemek icin: 2\nIstediginiz bir eczaneye ilac eklemek icin: 3\nIlac duzenlemek icin: 4\nBitirmek icin: 5"<<endl;
			        cin>>sec;
			        break;
		        }
		        case 3:{
		        	cout<<"Eczanenin id'sini giriniz:";
		        	cin>>sayi;
		        	cout<<"Eczane icin kayit edeceginiz ilac sayisini giriniz: ";
	                  cin>>miktar;
	                  
				      med[j].ilac_liste_olustur(med,miktar);
				    
				      file[sayi-1].open("ilac_listesi"+to_string(sayi)+".dat",ios::out | ios::in | ios::app );
				    
	                  for(int j=0; j<miktar; j++){
					   
	                     cout<<"\nIsim:"<<med[j].get_ilac_isim()<<"\t\tNo:"<<med[j].get_ilac_id()<<"\t\tFiyat:"<<med[j].get_ilac_fiyati()<<"\t\tAdet:"<<med[j].get_ilac_sayisi()<<endl;
	                     file[sayi-1]<<"\n"<<med[j].get_ilac_isim()<<"    "<<med[j].get_ilac_id()<<"    "<<med[j].get_ilac_fiyati()<<"    "<<med[j].get_ilac_sayisi()<<endl;
					  }
					  cout<<"\nILAC DOSYASINA EKLEME YAPILDI";
		        	
		            
					
					cout<<"\n\nEczane listesi ve ilaclarini olusturmak icin: 1\nYeni eczane ve ilac listesini eklemek icin: 2\nIstediginiz bir eczaneye ilac eklemek icin: 3\nIlac duzenlemek icin: 4\nBitirmek icin: 5"<<endl;
			        cin>>sec;
			        break;
		        }
		        case 4:{
				
			
			
			
			        cout<<"\n\nEczane listesi ve ilaclarini olusturmak icin: 1\nYeni eczane ve ilac listesini eklemek icin: 2\nIstediginiz bir eczaneye ilac eklemek icin: 3\nIlac duzenlemek icin: 4\nBitirmek icin: 5"<<endl;
			        cin>>sec;
			        break;
	
			    }
			    
		        default:{
				   break;
		        }
             }
		
           }
			
       }
			
			
			
   }
				
				
				
			
			
	else if(secim==2){
		cout<<"\nMUSTERI\n";
			
			cout<<"\n\nIlac goruntulemek icin: 1\nEczane listelemek icin: 2\nHerhangi bir eczaneyi gormek icin: 3\nHerhangi bir eczaneye ait ilac listesi: 4\nBitirmek icin: 5"<<endl;
			cin>>choose;
		
			while(choose != 5){
	
	           switch(choose){
		
	   	         case 1:{
					string ilac;
					cout<<"Aradiginiz ilacin ismini giriniz:";
					cin>>ilac;
					cout<<"-------------------------------------------------------------------------------------------------------";
					cout<<"\nEczane.1: Cem Eczanesi     Eczane.2: Faruk Eczanesi\tEczane.3: Gunes Eczanesi\tEczane.4: YENI\n";
					cout<<"\nILAC\tID\tFIYAT\tADET\n";
					ilac_ara(ilac);
					cout<<"\n-------------------------------------------------------------------------------------------------------";
					
					cout<<"\n\nIlac goruntulemek icin: 1\nEczane listelemek icin: 2\nHerhangi bir eczaneyi gormek icin: 3\nHerhangi bir eczaneye ait ilac listesi: 4\nBitirmek icin: 5"<<endl;
			        cin>>choose;
			        break;
			     }
			     
		         case 2:{
		         	
		         	eczn_listele();
		         	
				    cout<<"\n\nIlac goruntulemek icin: 1\nEczane listelemek icin: 2\nHerhangi bir eczaneyi gormek icin: 3\nHerhangi bir eczaneye ait ilac listesi: 4\nBitirmek icin: 5"<<endl;;
			        cin>>choose;
			        break;
		         }
		         
		         case 3:{
		            string nickname;
		            cout<<"Goruntulemek istediginiz eczanenin adini giriniz:";
		            cin>>nickname;
		            cout<<"\nECZANE\tID\tADRES\n";
		            eczn_goster(nickname);
				
			        cout<<"\n\nIlac goruntulemek icin: 1\nEczane listelemek icin: 2\nHerhangi bir eczaneyi gormek icin: 3\nHerhangi bir eczaneye ait ilac listesi: 4\nBitirmek icin: 5"<<endl;
			        cin>>choose;
			        break;
		         }
		         
		         case 4:{
		            cout<<"Eczane id'sini giriniz:";
		            cin>>ecz_no;
		            cout<<"\n------------------------------\n";
		            cout<<"ILAC\tID\tFIYAT\tADET\n\n";
		            eczn_ait_ilac_listesi(ecz_no);
		            cout<<"--------------------------------";
				
			        cout<<"\n\nIlac goruntulemek icin: 1\nEczane listelemek icin: 2\nHerhangi bir eczaneyi gormek icin: 3\nHerhangi bir eczaneye ait ilac listesi: 4\nBitirmek icin: 5"<<endl;
			        cin>>choose;
			        break;
		         }
			        
		         default:
			
			        break;
                }
		
           }
					
   }
				
	
	else{
	    cout<<"HATALI KULLANICI GIRISI !";
		
	}

	return 0;
	
}