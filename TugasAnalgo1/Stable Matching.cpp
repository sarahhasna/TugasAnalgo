/*
Nama			: Sarah Hasna Azzahra
Kelas			: B
NPM				: 140810170010
Nama program	: Stable Matching
*/
#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
  
#define N  5 //number man or woman
  
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1) 
{ 

    for (int i = 0; i < N; i++) 
    { 

        if (prefer[w][i] == m1) 
            return true; 

        if (prefer[w][i] == m) 
           return false; 
    } 
} 

void stableMarriage(int prefer[2*N][N]) 
{ 
    int wPartner[N]; 

    bool mFree[N]; 
  
    memset(wPartner, -1, sizeof(wPartner)); 
    memset(mFree, false, sizeof(mFree)); 
    int freeCount = N; 
  
    while (freeCount > 0) 
    { 
        int m; 
        for (m = 0; m < N; m++) 
            if (mFree[m] == false) 
                break; 
  
        for (int i = 0; i < N && mFree[m] == false; i++) 
        { 
            int w = prefer[m][i]; 
            if (wPartner[w-N] == -1) 
            { 
                wPartner[w-N] = m; 
                mFree[m] = true; 
                freeCount--; 
            } 
  
            else 
            { 
                int m1 = wPartner[w-N]; 
                if (wPrefersM1OverM(prefer, w, m, m1) == false) 
                { 
                    wPartner[w-N] = m; 
                    mFree[m] = true; 
                    mFree[m1] = false; 
                } 
            } 
        } 
    }
  
    cout << "Woman   Man" << endl; 
    for (int i = 0; i < N; i++) {
		cout << " " << i+N << "\t" << wPartner[i] << endl;
	}
} 
  
int main() 
{ 
	cout << "List Woman and Man\n";
	cout << "0. Victor\n";
	cout << "1. Wyatt\n";
	cout << "2. Xavier\n";
	cout << "3. Yancey\n";
	cout << "4. Zeus\n";
	cout << "5. Amy\n";
	cout << "6. Bertha\n";
	cout << "7. Clare\n";
	cout << "8. Diane\n";
	cout << "9. Erika\n";
		
	int prefer[2*N][N] = { {6, 5, 8, 9, 6}, 
        {8, 6, 5, 7, 9}, 
        {6, 9, 7, 8, 5}, 
        {5, 8, 7, 6, 9}, 
        {6, 8, 5, 9, 7}, 
        {4, 0, 1, 3, 2}, 
        {2, 1, 3, 0, 4}, 
        {1, 2, 3, 4, 0},
		{5, 4, 3, 2, 6},
		{3, 1, 4, 2, 0}, 
    }; 
    stableMarriage(prefer); 
    return 0; 
} 
