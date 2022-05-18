#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct auti{
	int red;
	char marka[50];
	char model[50];
	int godinap;
	int godinar;
	char ime[50];
	char VIN[20];
	
}a[20],pom;

void datoteka(int);
void ispis();
int brojanje();
void imeuz();
void imesil();
void goduz();
void godsil();		
void izbrisi();		
void dodaj();
void preime();
void pregod();
void premarka();
void zamjena();
void popravak();

int main(){
	int o;
	int menu,n,sort,search;
	
	FILE *broj;
	
	
	//Glavni izbornik
	printf(" ___          _    _               _  _         ______  \n");
	printf("| _ \\___ __ _(_)__| |_ _ _ __ _ __(_)(_)__ _   /|_||_\\`.__  \n");
	printf("|   / -_) _` | (_-<  _| '_/ _` / _| || / _` | (   _    _ _\\ \n");
	printf("|_|_\\___\\__, |_/__/\\__|_| \\__,_\\__|_|/ \\__,_| =`-(_)--(_)-' \n");
	printf("        |___/                      |__/      ");
	pocetak:
	printf("\n");
	printf("1.Kreiraj datoteku\n"
			"2.Ispisi podatke\n"
			"3.Ispis broja auta u bazi podataka\n"
			"4.Izbrisi registraciju\n"
			"5.Sortiranje\n"
			"6.Promjena podataka\n"
			"7.Pretrazivanje\n"
			"8.Dodavanje podatka\n"
			"9.Izadlji\n");
	printf("\nUpisite broj: ");
	scanf("%d",&menu);
	
	//Program za odabire u izborniku
	if(menu == 1){
	broj = fopen("Broj.txt","w");
	printf("Upisite zeljeni broj podataka: ");
	scanf("%d",&n);
	fprintf(broj,"%d",n);
	fclose(broj);
	datoteka(n);
	goto pocetak;
	}
	else if(menu == 2){
		ispis();
		goto pocetak;
	}
	else if(menu==3)
	{
		printf("Broj registriranih auta: %d\n",brojanje());
		goto pocetak;
	}
	else if(menu == 4)
	{
		izbrisi();
		goto pocetak;
	}
	else if(menu == 5)
	{
		opet:
		printf("\n1. Sortiraj uzlazno po imenu vlasnika(a-z)"
			   "\n2. Sortiraj silazno po imenu vlasnika(z-a)"
		       "\n3. Sortiraj uzlazno po godini proizvodnje"
			   "\n4. Sortiraj silazno po godini proizvodnje"
			   "\n5. Vrati se na izbornik");
			printf("\nUpisite broj: ");
		scanf("%d", &sort);
		
		switch(sort){
			case 1:imeuz(); goto pocetak;break;
			case 2:imesil(); goto pocetak;break;
		    case 3:goduz();goto pocetak;break;
			case 4:godsil();goto pocetak;break;
			case 5:goto pocetak;break;
			
			default:printf("\aUnesli ste krivi broj!\n");goto opet;break;
		}
	}
	else if(menu==6)
	{
		zamjena();
		goto pocetak;
	}
	else if(menu==7)
	{
		jad:
		printf("\n1. Pretrazivanje po imenu vlasnika"
			   "\n2. Pretrazivanje po godini proizvodnje"
			   "\n3. Pretrazivanje po marci"
			   "\n4. Vrati se na izbornik");
		printf("\nUpisite broj: ");
		scanf("%d",&search);
		
		switch(search){
			case 1:preime(); goto pocetak;break;
			case 2:pregod(); goto pocetak;break;
			case 3:premarka(); goto pocetak; break;
			case 4: goto pocetak;break;
			
			default:printf("\aUnesli ste krivi broj!\n");goto jad;break;
		}
		
	}
	else if(menu==8)
	{	
		dodaj();
		goto pocetak;
	}
	else if(menu==9){
	return 0;     
}
	else{
	printf("\nKrivi broj ste unesli!!\a\n");
	goto pocetak;
	}
	
	                            
}

//Funkcije_________________________________________________________________________________________________________________________________

//Upisivanje podataka
void datoteka(int n)
{
	FILE *dat;
	int i,br=0,v=0;
	long long int d;
	dat = fopen("Registracija.txt","w");
	
	for(i=0;i<n;i++){
	printf("Upisite marku auta: ");
	scanf(" %[^\n]%*c",a[i].marka);
	printf("Upisite model auta: ");
	scanf(" %[^\n]%*c",a[i].model);
	printf("Upisite godinu proizvodnje i isteka registracije auta: ");
	scanf("%d %d",&a[i].godinap,&a[i].godinar);
	printf("Upisite ime i prezime vlasnika: ");
	scanf(" %[^\n]%*c",a[i].ime);
	printf("Upisite VIN broj vozila: ");
	ponovo:
	v=0;
	scanf("%s",a[i].VIN);
	
	if(strlen(a[i].VIN)<17 || strlen(a[i].VIN)>17)
	{
		printf("VIN broj mora se sastojat od 17 znamenki!! \n");
		goto ponovo;
	}
	printf("\n");
}
	for(i=0;i<n;i++){
	a[i].red=i+1;
	fprintf(dat,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
}
	
	fclose(dat);

}
//Ispis podataka u datoteci
void ispis(){
	int i=0,br=0;
	FILE *dat;
	
	dat = fopen("Registracija.txt","r");
	
	while(fscanf(dat," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[i].red,a[i].marka,a[i].model,&a[i].godinap,a[i].ime,&a[i].godinar,a[i].VIN)==7)
	{
	printf("\n %d. Marka: %s Model: %s Godina proizvodnje: %d  ",a[i].red,a[i].marka,a[i].model,a[i].godinap);
	printf("Ime vlasnika: %s Godina isteka registracije: %d VIN: %s \n",a[i].ime,a[i].godinar,a[i].VIN);
	}
	

	fclose(dat);
}
//Ispis broja podataka u datoteci
int brojanje(){
	
	int i,br=0;
	FILE *dat;
	
	dat = fopen("Broj.txt","r");
	
	while(fscanf(dat,"%d",&br)==1)
	br = br;
	
	fclose(dat);
	return br;
}
//Sortiranje imena uzlazno
void imeuz(){
	
	FILE *dat,*dat1,*n;
	int i,j,br=0,k=0;
	
	dat = fopen("Registracija.txt","r");
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	for(k=0;k<br;k++)
	fscanf(dat," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[k].red,a[k].marka,a[k].model,&a[k].godinap,a[k].ime,&a[k].godinar,a[k].VIN);
		
	for(i=0;i<br-1;i++)
		for(j=i+1;j<br;j++)
			if(a[i].ime[0]>a[j].ime[0])
			{
				pom=a[i];
				a[i]=a[j];
				a[j]=pom;
			}
		
	fclose(dat);
	dat1 = fopen("Registracija.txt","w");
	
	for(i=0;i<br;i++){
	a[i].red=i+1;
	fprintf(dat1,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);	
}
	
	fclose(dat1);
	
}

//Sortiranje imena silazno
void imesil(){
	
	FILE *dat,*dat1,*n;
	int i,j,br=0,k=0;
	
	dat = fopen("Registracija.txt","r");
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	for(k=0;k<br;k++)
	fscanf(dat," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[k].red,a[k].marka,a[k].model,&a[k].godinap,a[k].ime,&a[k].godinar,a[k].VIN);
	
	for(i=0;i<br-1;i++)
		for(j=i+1;j<br;j++)
			if(a[i].ime[0]<a[j].ime[0])
			{
				pom=a[i];
				a[i]=a[j];
				a[j]=pom;
			}
		
			
		
	fclose(dat);
	dat1 = fopen("Registracija.txt","w");
	
	for(i=0;i<br;i++){
	a[i].red=i+1;
	fprintf(dat1,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);	
}
	
	fclose(dat1);
}

//Sortiranje godina silazno
void godsil(){
	FILE *dat,*dat1,*n;
	int i,j,br=0,k=0;
	
	dat = fopen("Registracija.txt","r");
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	for(k=0;k<br;k++)
	fscanf(dat, " %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[k].red,a[k].marka,a[k].model,&a[k].godinap,a[k].ime,&a[k].godinar,a[k].VIN);
		
	for(i=0;i<br-1;i++)
		for(j=i+1;j<br;j++)
			if(a[i].godinap > a[j].godinap){
						
				pom=a[i];
				a[i]=a[j];
				a[j]=pom;
			}
		
	fclose(dat);
	
	dat1 = fopen("Registracija.txt","w");
	for(i=0;i<br;i++){
	a[i].red=i+1;
	fprintf(dat1,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);	
}
	
	fclose(dat1);
	
}
//Sortiranje godina uzlazno

void goduz(){
	
	FILE *dat, *dat1, *n;
	
	int d,i,j,k,br=0;
	
	dat = fopen("Registracija.txt","r");
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	for(d=0;d<br;d++)
	fscanf(dat," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[d].red,a[d].marka,a[d].model,&a[d].godinap,a[d].ime,&a[d].godinar,a[d].VIN);
	
		
	for(i=0;i<br-1;i++)
		for(j=i+1;j<br;j++)
			if(a[i].godinap < a[j].godinap){
						
				pom=a[i];
				a[i]=a[j];
				a[j]=pom;
			}
	
	
	fclose(dat);
	dat1 = fopen("Registracija.txt","w");
	for(i=0;i<br;i++){
	a[i].red=i+1;
	fprintf(dat1,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);	
}
	
	fclose(dat1);
	
}

//Brisanje podatka
void izbrisi(){
	
	FILE *dat1, *dat2,*dat3, *n;
	
	int br=0,i,j,v=0;
	int broj;
	
	//Upis zeljenog podatka za brisanje
	ponovo:
	v=0;
	printf("Upisite broj podatka koji zelite obrisati: ");
	scanf("%d",&broj);
	


	
	n=fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	dat1 = fopen("Registracija.txt","r");
	dat2 = fopen("Zamjena.txt","w");
	dat3 = fopen("Delete.txt","w");
	
	for(i=0;i<br;i++)
	while(fscanf(dat1," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[i].red,a[i].marka,a[i].model,&a[i].godinap,a[i].ime,&a[i].godinar,a[i].VIN)==7)
	{
		if(broj != a[i].red){
		
		fprintf(dat2,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
	}
		else if(broj == a[i].red){
		
		fprintf(dat3,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
	}
	}
	
	fclose(dat1);
	fclose(dat2);
	fclose(dat3);
	
	remove("Delete.txt");
	remove("Registracija.txt");
	rename("Zamjena.txt","Registracija.txt");
	
	
	
	n = fopen("Broj.txt","w");
	br=br-1;
	fprintf(n,"%d",br);
	fclose(n);
	
	popravak();
	
}

//Dodavanje podatka na kraju dokumenta

void dodaj(){
	
	int n,br,i,v=0;

		FILE *broj_ul, *broj_iz,*dat;
		
		broj_ul = fopen("Broj.txt","r");
		fscanf(broj_ul,"%d",&br);
		fclose(broj_ul);
		
		printf("Koliko novih podataka zelite unesti: ");
		scanf("%d",&n);
		
		br=br+n;
		broj_iz = fopen("Broj.txt","w");
		fprintf(broj_iz,"%d",br);
		
		fclose(broj_iz);
		
	dat = fopen("Registracija.txt","a");

	for(i=0;i<n;i++){
		printf("Upisite marku auta: ");
		scanf(" %[^\n]%*c",a[i].marka);
		printf("Upisite model auta: ");
		scanf(" %[^\n]%*c",a[i].model);
		printf("Upisite godinu proizvodnje i isteka registracije auta: ");
		scanf("%d %d",&a[i].godinap,&a[i].godinar);
		printf("Upisite ime i prezime vlasnika: ");
		scanf(" %[^\n]%*c",a[i].ime);
		ponovo:
		v=0;
		printf("Upisite VIN broj: ");
		scanf("%s",a[i].VIN);
		if(strlen(a[i].VIN)<17 || strlen(a[i].VIN)>17)
		{
			printf("VIN broj mora se sastojat od 17 znamenki!! \n");
			goto ponovo;
		}
		printf("\n");
		
}
		
	for(i=0;i<n;i++){
		a[i].red=br-n+(i+1);
		fprintf(dat,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
	}
	
	fclose(dat);
	
}


//Pretrazivanje po imenu

void preime(){
	
	FILE *dat,*n;
	
	int i,j,br;
	char ime[50], prezime[50];
	
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	dat = fopen("Registracija.txt","r");
	
	printf("Unesite ime i prezime: ");
	scanf(" %[^\n]",ime);
	
	for(i=0;i<br;i++){
	while(fscanf(dat," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[i].red,a[i].marka,a[i].model,&a[i].godinap,a[i].ime,&a[i].godinar,a[i].VIN)==7)
	{
		if(strcmp(a[i].ime,ime)==0 )
		{
			printf("\n %d. Marka: %s Model: %s Godina proizvodnje: %d ",a[i].red,a[i].marka,a[i].model,a[i].godinap);
			printf("Ime vlasnika: %s Godina isteka registracije: %d VIN: %s\n",a[i].ime,a[i].godinar,a[i].VIN);
		}
		
	}
}

	fclose(dat);
}

//Pretrazivanje po godini proizvodnje
void pregod(){
	
	FILE *dat,*n;
	
	int i,j,br;
	int god;
	
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	dat = fopen("Registracija.txt","r");
	
	printf("Unesite godinu proizvodnje: ");
	scanf("%d",&god);
	
	for(i=0;i<br;i++)
	while(fscanf(dat," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[i].red,a[i].marka,a[i].model,&a[i].godinap,a[i].ime,&a[i].godinar,a[i].VIN)==7)
	{
		if(god == a[i].godinap)
		{
			printf("\n %d. Marka: %s Model: %s Godina proizvodnje: %d ",a[i].red,a[i].marka,a[i].model,a[i].godinap);
			printf("Ime vlasnika: %s Godina isteka registracije: %d VIN: %s\n",a[i].ime,a[i].godinar,a[i].VIN);
		}
		
	}
	
	fclose(dat);

}


//Pretrazivanje po marci
void premarka(){
	
	FILE *dat,*n;
	
	int i,j,br;
	char marka[50];
	
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	dat = fopen("Registracija.txt","r");
	
	printf("Unesite marku vozila: ");
	scanf(" %[^\n]",marka);
	
	for(i=0;i<br;i++)
	while(fscanf(dat," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[i].red,a[i].marka,a[i].model,&a[i].godinap,a[i].ime,&a[i].godinar,a[i].VIN)==7)
	{
		if(strcmp(a[i].marka,marka)==0)
		{
			printf("\n %d. Marka: %s Model: %s Godina proizvodnje: %d ",a[i].red,a[i].marka,a[i].model,a[i].godinap);
			printf("Ime vlasnika: %s Godina isteka registracije: %d VIN: %s\n",a[i].ime,a[i].godinar,a[i].VIN);
		}
		
	}
	
	fclose(dat);

}

//Zamjena podatka

void zamjena(){
	
	FILE *dat1, *dat2,*dat3, *n;
	
	int i,j,br,v=0;
	char VIN[20];
	int broj;
	n = fopen("Broj.txt","r");
	while(fscanf(n,"%d",&br)==1)
	br=br;
	fclose(n);
	
	printf("Upisite redni broj podatka za zamjenu: ");
	scanf("%d",&broj);
	
	dat1 = fopen("Registracija.txt","r");
	dat2 = fopen("Zamjena.txt","w");
	dat3 = fopen("Delete.txt","w");
	
	for(i=0;i<br;i++)
	while(fscanf(dat1," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[i].red,a[i].marka,a[i].model,&a[i].godinap,a[i].ime,&a[i].godinar,a[i].VIN)==7)
{
		if(broj!=a[i].red)
		fprintf(dat2,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
		
		else if(broj==a[i].red)
	{	
		fprintf(dat3,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
		
		printf("\nUpisite marku auta: ");
		scanf(" %[^\n]",a[i].marka);
		printf("Upisite model auta: ");
		scanf(" %[^\n]",a[i].model);
		printf("Upisite godinu proizvodnje i isteka registracije auta: ");
		scanf("%d %d",&a[i].godinap,&a[i].godinar);
		printf("Upisite ime i prezime vlasnika: ");
		scanf(" %[^\n]",a[i].ime);
		printf("Upisite VIN broj vozila: ");
		ponovo:
		scanf("%s",a[i].VIN);
		
		if(strlen(a[i].VIN)<17 || strlen(a[i].VIN)>17)
		{
			printf("VIN broj mora se sastojat od 17 znamenki!! \n");
			goto ponovo;
		}
		
		fprintf(dat2,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
	}
}

	fclose(dat1);
	fclose(dat2);
	fclose(dat3);
	
	remove("Delete.txt");
	remove("Registracija.txt");
	rename("Zamjena.txt","Registracija.txt");
	
}


void popravak(){
	
	FILE *br,*ul,*iz;
	int i,n;
	
	br = fopen("Broj.txt","r");
	while(fscanf(br,"%d",&n)==1)
	n=n;
	
	fclose(br);
	
	ul = fopen("Registracija.txt","r");
	iz = fopen("Zamjena.txt","w");
	
	for(i=0;i<n;i++)
	fscanf(ul," %d,%[^,],%[^,],%d,%[^,],%d,%s",&a[i].red,a[i].marka,a[i].model,&a[i].godinap,a[i].ime,&a[i].godinar,a[i].VIN);
	
	for(i=0;i<n;i++){
	a[i].red=i+1;
	fprintf(iz,"%d,%s,%s,%d,%s,%d,%s\n",a[i].red,a[i].marka,a[i].model,a[i].godinap,a[i].ime,a[i].godinar,a[i].VIN);
}
	
	fclose(ul);
	fclose(iz);
	
	remove("Registracija.txt");
	rename("Zamjena.txt","Registracija.txt");
}
