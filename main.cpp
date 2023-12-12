// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
struct Car{
    char model[20];
    double km;
    int seats;
};

struct Garage{
    double km_limit;
    Car *cars[10];
    int parked;
};

void park_car(Car &c, Garage g[],int s){
    Garage *g1= NULL;
    double diff=100000;
    for(int i=0;i<s;i++){
        if(g[i].parked < 10 && g[i].km_limit>=c.km){
            double d= g[i].km_limit-c.km;
            if(d< diff){
                diff=d;
                g1=&g[i];
            }
        }
    }
    
    if(g1 !=NULL){
        g1->cars[g1->parked] = &c;
        g1->parked++;
        
    }
}

void print_contance(Garage &g){
    for(int i=0;i<g.parked;i++){
        cout<<g.cars[i]->model<<" "<<g.cars[i]->km<<" km."<<endl;
    }
}

int main(){
     int n;
     cin>>n;
    Garage g[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            g[i].cars[j]=NULL;
        }
        g[i].parked=0;
        g[i].km_limit=1000*(i+1);
    }
    Car c;
    cin.getline(c.model,20);
     cin.getline(c.model,20);
     cin>>c.km;
     cin>>c.seats;
     park_car(c,g,n);
     Car c1;
     cin.getline(c1.model,20);
     cin.getline(c1.model,20);
     cin>>c1.km;
     cin>>c1.seats;
     park_car(c1,g,n);
     print_contance(g[0]);
    // cout<<"parked: " <<g[0].cars[0]->model<<endl;
   
    return 0;
}
