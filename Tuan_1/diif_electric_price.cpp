//CPP 
// tôi không muốn dùng if else
#include <bits/stdc++.h> 
using namespace std;

float gia_6_bac[7] = {0, 1.728, 1.786, 2.074, 2.612, 2.919, 3.015};
float thang_6_bac[7] = {0, 50, 100, 200, 300, 400};
float gia_5_bac[6] = {0, 1.728, 2.074, 2.612, 3.111, 3.457};
float thang_5_bac[6] = {0, 100, 200, 400, 700};

double tien_dien_6_bac(float kwh){
    double tienDien = 0;
    int bac = 1;
    while (bac<=6){
        if(bac==6) return tienDien += (kwh - thang_6_bac[bac-1])*gia_6_bac[bac];
        if (kwh > thang_6_bac[bac]) tienDien += (thang_6_bac[bac] - thang_6_bac[bac-1])*gia_6_bac[bac];
        else return tienDien += (kwh-thang_6_bac[bac-1])*gia_6_bac[bac];
        bac ++;
    }
    return tienDien;
    
}

double tien_dien_5_bac(int kwh){
    double tienDien = 0;
    int bac = 1;
    while (bac<=5){
        if(bac==5) return tienDien += (kwh - thang_5_bac[bac-1])*gia_5_bac[bac];
        if (kwh > thang_5_bac[bac]) tienDien += (thang_5_bac[bac] - thang_5_bac[bac-1])*gia_5_bac[bac];
        else return tienDien += (kwh-thang_5_bac[bac-1])*gia_5_bac[bac];
        bac ++;
    }
    return tienDien;
}

int main() 
{ 
    int kwh; cin >> kwh;
    printf("%.0f",(1.1*tien_dien_5_bac(kwh) - 1.1*tien_dien_6_bac(kwh))*1000);
    return 0;
}
