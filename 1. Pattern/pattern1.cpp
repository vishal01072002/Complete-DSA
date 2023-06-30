#include <iostream>
using namespace std;

void pattern1(){
    int n;
    cout << "enter value ";
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}

void pattern2(){
    int n;
    cout << "enter value of row ";
    cin >> n;

    int i=1, count=1;
    while (i<=n)
    {
        int j=1;
        while (j<=n)
        {
            cout<<count++;
            j++;

        }
        cout<<endl;
        
        i++;
    }
    
}

void pattern3(){
    // right angle triangle star
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int j=1;
        while (j<=i)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern4(){
    // right angle triangle --    1 ,22 ,333 ,4444
    int row;
    cout << "enter count of rows ";
    cin >> row;

    int i = 1;
    while (i <= row)
    {
        int col = 1;
        while (col<=i)
        {
            cout<<i;
            col++;
        }
        cout<<endl;
        i++;
        
    }
}

void pattern5(){
    // right angle triangle counting 1, 2 3, 4 5 6 === same A, BC, DEF, GHIJ 
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    int count = 1;
    while (row <= n)
    {
        int col=1;
        while (col <= row)
        {
            cout<<count++;
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern6(){
    // right angle triangle 
    /*
    1
    2 3
    3 4 5
    4 5 6 7

    A
    B C
    C D E
    D E F G
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        int col=1;
        int count = row;
        while (col <= row)
        {
            // ======== TRICK ==========
            // we can use (row + col - 1) instead of count
            // cout<<count++;
            cout<<row+col-1;
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern7(){
    // right angle triangle counting 1, 2 1, 3 2 1
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col = 1;
        while (col<=row)
        {
            cout<<row-col+1;
            col++;
        }
        cout<<endl;
        row++;
        
    }
    
}

void pattern8(){
    // rectangle counting AAA, BBB, CCC
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col = 1;
        while (col<=n)
        {
            cout<<char(65+row-1);
            // cout<<char('A'+row-1);
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern9(){
    // rectangle counting ABC, ABC, ABC
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col = 1;
        while (col<=n)
        {
            // cout<<char(65+col-1);
            cout<<char('A'+col-1);
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern10(){
    // rectangle counting ABC, DEF, GHI
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    int value = 0; 
    while (row<=n)
    {
        int col = 1;
        while (col<=n)
        {
            cout<<char('A'+ value++);
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern11(){
    // rectangle counting ABC, BCD, CDE
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col = 1;
        while (col<=n)
        {
            // ===== same as pattern 6 ========
            cout<<char('A'+(row+col-1) -1);
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern12(){
    // right angle triangle counting A, BB, CCC
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col = 1;
        while (col<=row)
        {
            cout<<char('A'+row-1);
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern13(){
    // right angle triangle counting D, CD, BCD, ABCD
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col=1;
        while (col<=row)
        {
            char ch = 'A' + (n-row+col) -1;
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
        
    }
}

void pattern14(){
    // mirror right angle triangle with spaces 
    /*
       *      
      **
     ***

        1
       23
      456
     78910
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        // we can also take 2 variables for space and star(*)
        int col = 1;
        while (col<=n-row)
        {
            cout<<' ';
            col++;
        }
        while (col<=n)
        {
            cout<<'*';
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern15(){
    // horizontal mirroe right angle triangle  
    /*
     ***
     **
     *
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col = 1;
        while (col<=n-row+1)
        {
            cout<<'*';
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern16(){
    /*
     ***
      **
       *
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int spaces = row-1;
        while (spaces)
        {
            cout<<' ';
            spaces--;
        }

        int stars = 1;
        while (stars <= n-row+1)
        {
            cout<<'*';
            stars++;
        }
        cout<<endl;
        row++;
    }
}

void pattern17(){
    /*
     111
      22
       3
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int spaces = row-1;
        while (spaces)
        {
            cout<<' ';
            spaces--;
        }

        int col = 1;
        while (col <= n-row+1)
        {
            cout<<row;
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern18(){
    /*
       1
      22
     333
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int spaces = n-row;
        while (spaces)
        {
            cout<<' ';
            spaces--;
        }

        int col = 1;
        while (col <= row)
        {
            cout<<row;
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern19(){
    /*
     1234
      234
       34
        4
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int spaces = row-1;
        while (spaces)
        {
            cout<<' ';
            spaces--;
        }

        int col = row;
        while (col <= n)
        {
            cout<<col;
            col++;
        }
        cout<<endl;
        row++;
    }
}

void pattern20(){
    /*
        1
       121
      12321
     1234321
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int spaces = n-row;
        while (spaces)
        {
            cout<<' ';
            spaces--;
        }

        int col = 1;
        while (col <= row)
        {
            cout<<col;
            col++;
        }

        int col2 = row-1;
        while (col2)
        {
            cout<<col2--;
        }
        
        cout<<endl;
        row++;
    }
}

void pattern21(){
    /*
    1234554321
    1234**4321
    123****321
    12******21
    1********1
    */
    int n;
    cout << "enter count of rows ";
    cin >> n;

    int row = 1;
    while (row<=n)
    {
        int col1 = 1;
        while (col1<=n-row+1)
        {
            cout<<col1;
            col1++;
        }

        // starts
        int star = 2*(row-1);
        while (star)
        {
            cout<<'*';
            star--;
        }

        int col2 = n-row+1;
        while (col2)
        {
            cout<<col2--;
        }
        
        cout<<endl;
        row++;
    }
}

int main()
{

    // pattern1();
    // pattern2();
    // pattern3();
    // pattern4();
    // pattern5();
    // pattern6();
    // pattern7();
    // pattern8();
    // pattern9();
    // pattern10();
    // pattern11();
    // pattern12();
    // pattern13();
    // pattern14();
    // pattern15();
    // pattern16();
    // pattern17();
    // pattern18();
    // pattern19();
    // pattern20();
    // pattern21();
    pattern21();

    return 0;
}