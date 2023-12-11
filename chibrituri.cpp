#include <fstream>
#include <cstring>
using namespace std;
int main()
{
  ifstream f("chibrituri.in");
  int n, m;
  f >> n >> m;
  f.close();
  int cv[]={4,2,2,2,3,2,3,2,4,3};
  int co[]={2,0,3,3,1,3,3,1,3,3};
  int nv=0;
  char smin[]="23:59", smax[]="00:00";
  for (int a = 0; a <= 2; a++)
    for (int b = 0; b <= 9; b++)
    {
      if (a == 2 && b > 3) break;
      for (int c = 0; c <= 5; c++)
        for (int d = 0; d <= 9; d++)
        {
          int ncv = cv[a]+cv[b]+cv[c]+cv[d];
          int nco = co[a]+co[b]+co[c]+co[d];
          if (ncv == n && nco == m)
          {
            nv++;
            char s[6];
            s[0]='0'+a, s[1]='0'+b, s[2]=':';
            s[3]='0'+c, s[4]='0'+d, s[5]=0;
            if (strcmp(s, smin) < 0) strcpy(smin, s);
            if (strcmp(s, smax) > 0) strcpy(smax, s);
          }
        }
    }
  ofstream g("chibrituri.out");
  g << nv << '\n' << smin << '\n' << smax;
  g.close();
  return 0;
}

