

#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n)
{LL ret=1;LL b=a;while(n) {if(n&1)
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
#define MAXK 100005
#define MAXN 1000000000
int ar[MAXK];
int get(int n, int k){
    int i=0;
    while(i<k and ar[i]<=n)i++;
    return n-i;
}

int main(){
    /*Declarations */

    int arr[8][5] = {0};
    vector<int> arrnum;
    int t,x,k,i;sd(t);k=6;
    for(i=0;i<t;i++)
    {
        cin>>x;arrnum.pb(x);

    }
    /*-----------------------------*/


    /*Binary conversion*/
    for(int j=0;j<t;j++)
    {
        int num = arrnum[j];
        for(int i=0;i<8;i++)
        {
            if(num!=0)
            {
                arr[i][j] = num%2;
                num /= 2;
            }
            cout<<arr[i][j]<<" ";

        }
cout<<endl;
    }

/*-----------------------------*/



    /*first MSB traversal*/

    vector<int> res;
    int count0=0,count1=0;
    for(int i=0;i<t;i++)
    {
        if(arr[7][i]==0) count0++;
        else count1++;
    }
    if(count0>count1) res.pb(0);
    else res.pb(1);
/*-----------------------------*/




    vector<int> res_temp;
    while(k>=0)
    {
        count0=0;count1=0;
        res_temp.clear();
        for(int i=0;i<t;i++)
        {
            int k_temp = k+1;
            int r_temp = res.size()-1;
            bool flag = true;
            while(k_temp<=7)
            {
                if(arr[k_temp][i] != res[r_temp])
                {
                    flag=false;
                    break;
                }
                k_temp++;
                r_temp--;
            }
            if(flag==false)
            {
                if(arr[k][i]==0) res_temp.pb(1);
                else res_temp.pb(0);
            }
            else
            {
                res_temp.pb(arr[k][i]);
            }
        }//end of for

        for(int i=0;i<t;i++)
        {
            if(res_temp[i]==0) count0++;
            else count1++;
        }
        if(count0>count1) res.pb(0);
        else res.pb(1);
        cout<<"res_temp: k = "<<k<<"- ";
        for(int i=0;i<t;i++)
        {
            cout<<res_temp[i]<<" ";
        }
        cout<<" / res : ";
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        k--;


    }//end of while


for(int i=0;i<res.size();i++) cout<<res[i]<<" ";

    return 0;
}

