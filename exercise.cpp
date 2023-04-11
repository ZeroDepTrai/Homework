#include <iostream>
using namespace std;
//check ki tu in hoa
bool kyTuInHoa(char n);
// check Ky tu in thuong
bool kyTuInThuong(char n);
//dem ki tu in thuong va in hoa
void dem(string str);
//tinh day fibonanci
int fibonanci(int n);
//fibo cach 2
int fibo(int n);
//tinh so ngay cach ngay dau tien trong nam
int ngay1(int ngay, int thang, int nam);
//ham tinh ngay lien sau
void ngayLienSau(int& ngay, int& thang, int& nam);
//ham tinh ngay lien trc
void ngayLienTruoc(int& ngay, int& thang, int& nam);
//ham tinh N ngay sau vd N=10 1/6/2003->11/6/2003
void congThemNgay(int& ngay, int& thang, int& nam, int n);
// ham nhap va kiem soat dau vao:
void nhapNgay(int& ngay, int& thang, int& nam);
//ham check ngay thang nam hop le hay khong
bool checkNgay(int ngay, int thang, int nam);
//ham check nam nhuan
bool checkNamNhuan(int nam);

int main()
{
    int ngay, thang, nam;
    nhapNgay(ngay, thang, nam);
    cout << "Ngay lien sau cua ngay " << ngay << "/" << thang << "/" << nam << " la: ";
    ngayLienTruoc(ngay,thang,nam);
    cout << ngay << "/" << thang << "/" << nam;
	return 0;
}
//check nam nhuan
bool checkNamNhuan(int nam)
{
    return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) ? 1 : 0;
}
//ham check ngay thang nam hop le
bool checkNgay(int ngay, int thang, int nam)
{
    int thangNam[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (nam >= 0)
    {
        if (thang <= 12 && thang >= 1)
        {
            if (checkNamNhuan(nam))
            {
                thangNam[2] = 29;
                if (ngay <= thangNam[thang])
                {
                    return 1;
                }
                else
                    return 0;
            }
            else
            {
                if (ngay <= thangNam[thang])
                {
                    return 1;
                }
                else
                    return 0;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}
//ham nhap
void nhapNgay(int& ngay, int& thang, int& nam)
{
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
    while (!checkNgay(ngay, thang, nam))
    {
        system("cls");
        cout << "Ngay khong ton tai, nhap lai! \n";
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }
}
//tinh so ngay cach ngay dau tien trong nam
int ngay1(int ngay, int thang, int nam)
{
    int soNgay = 0;
    int thangKhongNhuan[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int thangNhuan[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    if (checkNamNhuan(nam))
    {
        for (int i = 1; i < thang; i++)
        {
            soNgay += thangNhuan[i];
        }
    }
    else
    {
        for (int i = 1; i < thang; i++)
        {
            soNgay += thangKhongNhuan[i];
        }
    }
    soNgay += ngay;
    return soNgay;
}
//Ngay lien sau
void ngayLienSau(int& ngay, int& thang, int& nam)
{
    int thangKhongNhuan[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int thangNhuan[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    if (checkNamNhuan(nam))
    {
        if (ngay < thangNhuan[thang])
        {
            ngay++;
        }
        else
        {
            ngay = 1;
            if (thang == 12)
            {
                thang = 1;
                nam++;
            }
            else
                thang++;
        }
    }
    else
    {
        if (ngay < thangKhongNhuan[thang])
        {
            ngay++;
        }
        else
        {
            ngay = 1;
            if (thang == 12)
            {
                thang = 1;
                nam++;
            }
            else
                thang++;
        }
    }
}
//ham tinh ngay lien truoc =))
void ngayLienTruoc(int& ngay, int& thang, int& nam)
{
    int thangKhongNhuan[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int thangNhuan[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    if (checkNamNhuan(nam))
    {
        if (ngay == 1)
        {
            if (thang == 1)
            {
                ngay = thangNhuan[12];
                thang = 12;
                nam--;
            }
            else
            {
                ngay = thangNhuan[thang - 1];
                thang--;
            }
        }
        else
        {
            ngay--;
        }
        
    }
    else
    {
        if (ngay == 1)
        {
            if (thang == 1)
            {
                ngay = thangKhongNhuan[12];
                thang = 12;
                nam--;
            }
            else
            {
                ngay = thangNhuan[thang - 1];
                thang--;
            }
        }
        else
        {
            ngay--;
        }
    }
}
void congThemNgay(int& ngay, int& thang, int& nam, int n)
{
    int thangKhongNhuan[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int thangNhuan[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    if (checkNamNhuan(nam))
    {
        if (ngay + n < thangNhuan[thang])
        {
            ngay += n;
        }
        else
        {
            ngay += n - thangNhuan[thang];
            if (thang == 12)
            {
                thang = 1;
                nam++;
            }
            else
                thang++;
        }
    }
    else
    {
        if (ngay + n < thangKhongNhuan[thang])
        {
            ngay += n;
        }
        else
        {
            ngay += n - thangKhongNhuan[thang];
            if (thang == 12)
            {
                thang = 1;
                nam++;
            }
            else
                thang++;
        }
    }
}
int fibonanci(int n)
{
    int a[100];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
int fibo(int n)
{
    int a = 0, b = 1, i = 2, c;
    c = a + b;
    if (n == 0)
        return a;
    else
        if(n==1)
            return b;
    while (i <= n)
    {
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    return c;
}
void dem(string str)
{
    int demHoa = 0, demThuong = 0;
    for (int i = 0; i <= str.length(); i++)
    {
        if (kyTuInThuong(str[i]))
        {
            demThuong++;
        }
        else
        {
            if (kyTuInHoa(str[i]))
            {
                demHoa++;
            }
        }
    }
    cout << "chuoi co " << demHoa << " chu in hoa\n";
    cout << "chuoi co " << demThuong << " chu in thuong\n";
}
bool kyTuInThuong(char n)
{
    if (n * 1 >= 97 && n * 1 <= 122)
    {
        return 1;
    }
    return 0;
}
bool kyTuInHoa(char n)
{
    if (n * 1 >= 65 && n * 1 <= 90)
    {
        return 1;
    }
    return 0;
}