#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

using namespace std;

string teamNames[MAX];
int points[MAX], wins[MAX], ties[MAX], losses[MAX], goalsScored[MAX], goalsAgainst[MAX];

string stringLowerCase(string s)
{
  string r = "";
  for(int i=0; i<s.size(); i++)
  {
    if(s[i] < 97)
      r+=(s[i] + 32);
    else
      r+=s[i];
  }
  return r;
}

/* -1 => _p1<_p2; 1 => _p1>_p2; 0 => _p1=_p2; */
int compareTeams(const void *_p1, const void *_p2)
{
  int it1 = * (int *) _p1;
  int it2 = * (int *) _p2;
  
  if(points[it1] > points[it2])
    return -1;
  else if(points[it1] < points[it2])
    return 1;
  else
    if(wins[it1] > wins[it2])
      return -1;
    else if(wins[it1] < wins[it2])
      return 1;
    else
      if((goalsScored[it1]-goalsAgainst[it1]) > (goalsScored[it2]-goalsAgainst[it2]))
        return -1;
      else if((goalsScored[it1]-goalsAgainst[it1]) < (goalsScored[it2]-goalsAgainst[it2]))
        return 1;
      else
        if(goalsScored[it1] > goalsScored[it2])
          return -1;
        else if(goalsScored[it1] < goalsScored[it2])
          return 1;
        else
          if((wins[it1]+ties[it1]+losses[it1]) < (wins[it2]+ties[it2]+losses[it2]))
            return -1;
          else if((wins[it1]+ties[it1]+losses[it1]) > (wins[it2]+ties[it2]+losses[it2]))
            return 1;
          else
          {
            string st1 = stringLowerCase(teamNames[it1]);
            string st2 = stringLowerCase(teamNames[it2]);
            return st1.compare(st2);
          }
}

string readUntilChar(char c)
{
  string res="";
  char temp;
  while(scanf("%c",&temp) != EOF)
  {
    if(temp != c)
      res+=temp;
    else
      break;
  }
  return res;
}

int main()
{
  int ncases, nteams, ngames;
  string tournamentName, team1, team2;
  int score1, score2;
  int flagScoresRecorded;
  int teamIndex[MAX];
  char temp;
  int primeravez = 1;
  
  scanf("%d\n",&ncases);
//  cout<<"ncases "<<ncases<<endl;
  for(int i=0; i<ncases; i++)
  {
    if(primeravez)
      primeravez = 0;
    else
      cout<<endl;
      
    tournamentName = readUntilChar('\n');
    scanf("%d\n", &nteams);
//    cout<<"nteams "<<nteams<<endl;
    for(int j=0; j<nteams; j++)
    {
      teamNames[j] = readUntilChar('\n');
      points[j]=wins[j]=ties[j]=losses[j]=goalsScored[j]=goalsAgainst[j]=0;
      teamIndex[j] = j;
    }
    scanf("%d\n", &ngames);
//    cout<<"ngames "<<ngames<<endl;
    for(int j=0; j<ngames; j++)
    {
      team1 = readUntilChar('#');
      scanf("%d@%d#",&score1, &score2);
//      cout<<"scores "<<score1<<" "<<score2<<endl;
      team2 = readUntilChar('\n');
      flagScoresRecorded = 0;
      for(int k=0; k<nteams; k++)
      {
 //       cout<<teamNames[k]<<" - "<<team1<<" - "<<team2<<" - "<<endl;
        if(teamNames[k] == team1)
        {
          if(score1>score2)
          {
            points[k]+=3;
            wins[k]++;
          }
          else if(score1==score2)
          {
//      cout<<"scores "<<score1<<" "<<score2<<endl;
            points[k]++;
            ties[k]++;
          }
          else
          {
            losses[k]++;
          }
          goalsScored[k]+=score1;
          goalsAgainst[k]+=score2;
          flagScoresRecorded++;
        }
        else if(teamNames[k] == team2)
        {
          if(score1<score2)
          {
            points[k]+=3;
            wins[k]++;
          }
          else if(score1==score2)
          {
            points[k]++;
            ties[k]++;
          }
          else
          {
            losses[k]++;
          }
          goalsScored[k]+=score2;
          goalsAgainst[k]+=score1;
          flagScoresRecorded++;
        }
        if(flagScoresRecorded == 2) break;
      }
    }

    cout<<tournamentName<<endl;
    int index;
    qsort(teamIndex,nteams,sizeof(int),compareTeams);
    for(int j=0; j<nteams; j++)
    {
      index = teamIndex[j];
      cout<<(j+1)<<") "<<teamNames[index]<<" "<<points[index]<<"p, "<<(wins[index]+ties[index]+losses[index]);
      cout<<"g ("<<wins[index]<<"-"<<ties[index]<<"-"<<losses[index]<<"), ";
      cout<<(goalsScored[index]-goalsAgainst[index])<<"gd ("<<goalsScored[index]<<"-"<<goalsAgainst[index]<<")"<<endl;
    }
  }
  
  return 0;
}
