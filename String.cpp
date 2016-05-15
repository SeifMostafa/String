#include "String.h"
String::String ()
{
    arr = new char [1000];
    arr[0] = '\0';
    SIZE = 0 ;
}
void String::setarr(char* x)
{
    arr=x;
}
void String::setSIZE(int x)
{
    SIZE=x;
}
char* String::getarr(){return arr;}
int String::getsize(){return SIZE;}
int String::Find (String x)
{

    for(int i=0; i<SIZE; i++)
    {
        if (arr[i]== x.arr[0])
        {
            int l = i ;
            int m = i+1 ;
            int j ;

            for (j = 1 ; j < x.SIZE ; j++ )
            {
                if (arr[m]==x.arr[j])
                {
                    m++ ;
                    continue ;
                }
                else break ;

            }

           /* while (c[j]!='\0')
            {
                if (arr[m]==c[j])
                    {
                        m++ ;
                        j++ ;
                        continue ;
                    }
                    else break ;
            }*/

            if (j==x.SIZE) return l ;
        }
    }
    return -1 ;
}


bool String::Isempty()
{
    if(SIZE==0)
    {
        return true;
    }
    else return false;
}
int String::str_length()
{
    return SIZE ;
}


istream &operator >> (istream & in , String &x)
{

    char c;
    in.get(c) ;
    while (c!='\n')
    {
        x.arr[x.SIZE]=c;
        x.SIZE++ ;
        in.get(c);

    }
    return in ;
}


ostream &operator << (ostream & out , String & x)
{
    for (int i=0 ; i < x.SIZE ; i++)
    {
        out << x.arr[i] ;
    }
    return out ;
}


void String::operator =(const String &x)
{
    SIZE = x.SIZE ;

    for (int i=0 ; i < x.SIZE ; i++)
    {
        arr[i] = x.arr[i] ;

    }
}


char String::getat (int n)
{
       if(n>SIZE)
    {
       cout<<-1;
       return 0;
    }
    else return arr[n] ;
}
String String::replacing(String old,String NEW)
{
    int x ;
   while (this->Find(old)!=-1)
   {
       x = this->Find(old) ;
       int l = old.SIZE ;
       this->Erase(x , l) ;
       int j = NEW.SIZE ;

       int p = SIZE ;

       SIZE+=NEW.SIZE ;

       for (int i = p-1 ; i >=x ; i-- )
       {
           arr[i+j]=arr[i];
       }

       int m = 0 ;

       for (int i=x ; i < x+NEW.SIZE ; i++)
       {
           arr[i] = NEW.arr[m] ;
           m++;
       }
   }

   return *this ;
}


void String::ToLower()
{
    for(int i=0; i<SIZE; i++)
    {
        if((int)arr[i]>=65&&(int)arr[i]<=90)
            arr[i]=(int)arr[i]+32;
    }
}


void String::ToUpper()
{
    for(int i=0; i<SIZE; i++)
    {
        if((int)arr[i]>=97&&(int)arr[i]<=122)
            arr[i]=(int)arr[i]-32;

    }
}
String String::append(String x)
{
    for(int i=1; i<=x.SIZE; i++)
    {
        arr[SIZE]=x.arr[i-1];
        SIZE++;
    }
    return *this;
}
String String::substring(int x , int y)
{
    String z ;
    z.SIZE= y ;
    int j = 0 ;
    for (int i=x ; i <x+y; i++)
    {
        z.arr[j]= arr[i];
        j++ ;
    }
    return z ;
}
void String::Erase(int x,int y)
{
    int z = x+y ;
    int l = x ;
    int m = SIZE ;
    for(int i=z; i<m; i++)
    {
        arr[l]=arr[i];
        l++ ;
    }
    SIZE-=y ;
}


void String::showjustify(name::enumration x)
{

    bool yy=false;
    if (x == name::left)
    {yy=true;}

    bool zz=false;
     if (x == name::right)
    {zz=true;}

     bool ww=false;
     if(x== name::Justify)
        {ww=true;}
    if(yy)
    {
        for(int i=0; i<SIZE; i++)
            cout<<arr[i];
    }
    //for Right
    else if(zz)
    {
        if(SIZE>80)
        {
            int mo=SIZE%80;

            for(int i=0; i<(SIZE-mo); i++)
                cout<<arr[i];
            for(int i=80; i>mo; i--)
                cout<<" ";
            for(int i=0; i<mo; i++)
                cout<<arr[SIZE-1-i];
        }
        else
        {
            for(int i=0; i<(80-SIZE); i++)
                cout<<" ";
            for(int i=0; i<SIZE; i++)
                cout<<arr[i];
        }

    }
    //for middle
    else if(ww)
    {
        if(SIZE>80)
        {
            int mo=SIZE%80;

            for(int i=0; i<(SIZE-mo); i++)
                cout<<arr[i];
            for(int i=40; i>(mo/2); i--)
                cout<<" ";
            for(int i=0; i<mo; i++)
                cout<<arr[SIZE-1-i];
        }
        else
        {
          for(int i=0; i<((80-SIZE)/2); i++)
            cout<<" ";
        for(int i=0; i<SIZE; i++)
            cout<<arr[i];
        }

    }
    else cout<<"undefined order";
}
void String ::Reverse()
{
    int spaces=0;
    for(int i=0; i<SIZE; i++)
    {
        if(arr[i]==32)
        {
            spaces++;
        }
    }
    if(spaces>0)
    {
        String temp,z;
        int j=0,h=0;
        for(int i=(SIZE-1); i>=0; i--)
        {
            if(arr[i]==32)
            {
                for(int w=(j-1); w>=0; w--)
                {
                    z.arr[h]=temp.arr[w];
                    h++;
                }
                z.arr[h]=32;
                h++;
                j=0;
            }
            else if(i==0)
            {
                if(i==0)
                {
                    temp.arr[j] =arr[i];
                    j++;
                }
                for(int w=(j-1); w>=0; w--)
                {
                    z.arr[h]=temp.arr[w];
                    h++;
                }
            }
            else
            {
                temp.arr[j] =arr[i];
                j++;
            }


        }
        arr = z.arr;
    }
}
int String::Compare(String x)
{
    int z ;

    if (SIZE<x.SIZE) z = SIZE ;
    else z = x.SIZE ;

    for (int i = 0 ; i < z ; i++ )
    {
        if (arr[i]<x.arr[i]) return -1 ;

        else if (arr[i]>x.arr[i]) return 1 ;

        else continue ;

    }

    if (SIZE<x.SIZE) return -1 ;
    else if (SIZE>x.SIZE) return 1 ;

    return 0 ;
}
void Sort(String*arr , int x)
{
    int z ;

    String s , m ;

     for (int i = 0 ; i < x-1 ; i++ )
     {
         for (int j=i+1 ; j < x ; j++)
         {

             s = arr[j] ;
             m = arr[i] ;

             s.ToLower();
             m.ToLower();


             if (arr[i].SIZE < arr[j].SIZE )
             {
                 z = arr[i].SIZE ;
             }
             else {z=arr[j].SIZE ;}


             for (int l = 0 ; l < z ; l++)
             {



                 if (s.arr[l]<m.arr[l])
                 {
                     Swap (arr[i] , arr[j]) ;

                     break ;
                 }



                 else if(s.arr[l]>m.arr[l])
                 {
                     break ;
                 }


                 else {continue ;}


             }
         }
     }
}



void Swap (String &z , String &s)
{
    String m ;

    m = s ;

    s = z ;

    z = m ;
}

String::~String()
{
    delete [] arr ;
}
