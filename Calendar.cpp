#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
public:
    int date;
    int month;
    int year;
    Date(int d=0,int m=0,int y=0)
    {
        date=d;
        month=m;
        year=y;
    }
    void get()
    {
        cout<<"\nPlease enter the date(DD MM YYYY) for specific search:  ";
        cin>>date>>month>>year;
    }
    void display()
    {
        cout<<", "<<date<<"/"<<month<<"/"<<year<<endl;
    }
};

bool isLeap(Date D)
{
    int y=D.year;
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)
            {
                return true;
            }
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;

}

bool isValid(Date D)
{
    int d=D.date,m=D.month,y=D.year;
    if(y<=0 || m<=0 ||d<=0)
        return false;
    switch (m)
    {
    case 1:
        if(d>31)
            return false;
        break;
    case 2:
        if(isLeap(D))
        {
            if(d>29)
                return false;
        }
        else
        {
            if(d>28)
                return false;
        }
        break;
    case 3:
        if(d>31)
            return false;
        break;
    case 4:
        if(d>30)
            return false;
        break;
    case 5:
        if(d>31)
            return false;
        break;
    case 6:
        if(d>30)
            return false;
        break;
    case 7:
        if(d>31)
            return false;
        break;
    case 8:
        if(d>31)
            return false;
        break;
    case 9:
        if(d>30)
            return false;
        break;
    case 10:
        if(d>31)
            return false;
        break;
    case 11:
        if(d>30)
            return false;
        break;
    case 12:
        if(d>31)
            return false;
        break;
    default:
        return false;
    }
    return true;
}

void nextDate(Date& D)
{
    if(isValid(D))
    {
        D.date++;
        if(!isValid(D))
        {
            D.date=1;
            D.month++;
        }
        if(!isValid(D))
        {
            D.month=1;
            D.year++;
        }
    }
}

bool isSame( Date d1,Date d2)
{
    if(d1.date==d2.date&&d1.month==d2.month&&d1.year==d2.year)
        return true;
    else
        return false;
}

int countDay(Date D)
{
    Date d(1,1,1);
    int countno=1;
    while(!isSame(d,D))
    {
        nextDate(d);
        countno++;
    }

    //cout<<countno<<endl;

    return countno;
}
void printDay(Date D)
{
    int cd=countDay(D);
    int a=(cd-1)%7;
    switch(a)
    {
    case 0:
        cout<<"Monday";
        break;
    case 1:
        cout<<"Tuesday";
        break;
    case 2:
        cout<<"Wednesday";
        break;
    case 3:
        cout<<"Thursday";
        break;
    case 4:
        cout<<"Friday";
        break;
    case 5:
        cout<<"Saturday";
        break;
    case 6:
        cout<<"Sunday";
        break;

    }
}
void displayMonth(int i)
{
    switch(i)
    {
    case 1:
        cout<<"January";
        break;
    case 2:
        cout<<"February";
        break;
    case 3:
        cout<<"March";
        break;
    case 4:
        cout<<"April";
        break;
    case 5:
        cout<<"May";
        break;
    case 6:
        cout<<"June";
        break;
    case 7:
        cout<<"July";
        break;
    case 8:
        cout<<"August";
        break;
    case 9:
        cout<<"September";
        break;
    case 10:
        cout<<"October";
        break;
    case 11:
        cout<<"November";
        break;
    case 12:
        cout<<"December";
        break;
    default:
        cout<<"...";
        break;
    }
}

void displayByYear(int dyear)
{
    Date D;
    D.date=1;
    D.month=1;
    D.year=dyear;
    int dcount= countDay(D);
    for(int i=1; i<13; i++)
    {
        cout<<"\n\n";
        displayMonth(i);
        cout<<", "<<dyear;
        cout<<"\n  M  T  W  T  F  S  S\n";
        int k=(dcount-1)%7;
        for(int j=0; j<k; j++)
            cout<<setw(3)<<" ";
        while(isValid(D))
        {
            cout<<setw(3)<<D.date;
            if(dcount%7==0)
                cout<<"\n";
            D.date++;
            dcount++;
        }
        D.date=1;
        D.month++;

    }
}

int main()
{
    int y;
    cout<<"enter a year(YYYY) to view its calender\n";
    cin>>y;
    if(y>0)
    {
        displayByYear(y);
    }
    Date d;
ad:
    d.get();
    if(isValid(d))
    {
        printDay(d);
        //d.display();
        cout<<", "<<d.date<<" ";
        displayMonth(d.month);
        cout<<" "<<d.year<<endl;
    }
    else
    {
        cout<<"invalid date\nEnter 1 to search again:  ";
        int x;
        cin>>x;
        if(x!=1)
            exit(1);
    }

    goto ad;

    return 0;

}

