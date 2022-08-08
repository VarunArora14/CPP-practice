
/*
B. Silly Mistake
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Central Company has an office with a sophisticated security system. There are
10
6
106
employees, numbered from
1
1
to
10
6
106
.
The security system logs entrances and departures. The entrance of the
i
i
-th employee is denoted by the integer
i
i
, while the departure of the
i
i
-th employee is denoted by the integer
−i
−i
.
The company has some strict rules about access to its office:
An employee can enter the office at most once per day.
He obviously can't leave the office if he didn't enter it earlier that day.
In the beginning and at the end of every day, the office is empty (employees can't stay at night). It may also be empty at any moment of the day.
Any array of events satisfying these conditions is called a valid day.
Some examples of valid or invalid days:
[1,7,−7,3,−1,−3]
[1,7,−7,3,−1,−3]
is a valid day (
1
1
 enters,
7
7
enters,
7
7
leaves,
3
3
enters,
1
1
leaves,
3
3
leaves).
[2,−2,3,−3]
[2,−2,3,−3]
is also a valid day.
[2,5,−5,5,−5,−2]
[2,5,−5,5,−5,−2]
is not a valid day, because
5
5
entered the office twice during the same day.
[−4,4]
[−4,4]
is not a valid day, because
4
4
left the office without being in it.
[4]
[4]
is not a valid day, because
4
4
entered the office and didn't leave it before the end of the day.
There are
n
n
events
a
1
,
a
2
,…,
a
n
a1,a2,…,an
, in the order they occurred. This array corresponds to one or more consecutive days. The system administrator erased the dates of events by mistake, but he didn't change the order of the events.
You must partition (to cut) the array
a
a
of events into contiguous subarrays, which must represent non-empty valid days (or say that it's impossible). Each array element should belong to exactly one contiguous subarray of a partition. Each contiguous subarray of a partition should be a valid day.
For example, if
n=8
n=8
and
a=[1,−1,1,2,−1,−2,3,−3]
a=[1,−1,1,2,−1,−2,3,−3]
then he can partition it into two contiguous subarrays which are valid days:
a=[1,−1 | 1,2,−1,−2,3,−3]
a=[1,−1 | 1,2,−1,−2,3,−3]
.
Help the administrator to partition the given array
a
a
in the required way or report that it is impossible to do. Find any required partition, you should not minimize or maximize the number of parts.
Input
The first line contains a single integer
n
n
(
1≤n≤
10
5
1≤n≤105
).
The second line contains
n
n
integers
a
1
,
a
2
,…,
a
n
a1,a2,…,an
(
−
10
6
≤
a
i
≤
10
6
−106≤ai≤106
 and
a
i
≠0
ai≠0
).
Output
If there is no valid partition, print
−1
−1
. Otherwise, print any valid partition in the following format:
On the first line print the number
d
d
of days (
1≤d≤n
1≤d≤n
).
On the second line, print
d
d
integers
c
1
,
c
2
,…,
c
d
c1,c2,…,cd
(
1≤
c
i
≤n
1≤ci≤n
 and
c
1
+
c
2
+…+
c
d
=n
c1+c2+…+cd=n
), where
c
i
ci
is the number of events in the
i
i
-th day.
If there are many valid solutions, you can print any of them. You don't have to minimize nor maximize the number of days.
Examples
Input
Copy
6
1 7 -7 3 -1 -3
Output
Copy
1
6
Input
Copy
8
1 -1 1 2 -1 -2 3 -3
Output
Copy
2
2 6
Input
Copy
6
2 5 -5 5 -5 -2
Output
Copy
-1
Input
Copy
3
-8 1 1
Output
Copy
-1
Note
In the first example, the whole array is a valid day.
In the second example, one possible valid solution is to split the array into
[1,−1]
[1,−1]
and
[1,2,−1,−2,3,−3]
[1,2,−1,−2,3,−3]
(
d=2
d=2
 and
c=[2,6]
c=[2,6]
). The only other valid solution would be to split the array into
[1,−1]
[1,−1]
,
[1,2,−1,−2]
[1,2,−1,−2]
and
[3,−3]
[3,−3]
(
d=3
d=3
 and
c=[2,4,2]
c=[2,4,2]
). Both solutions are accepted.
In the third and fourth examples, we can prove that there exists no valid solution. Please note that the array given in input is not guaranteed to represent a coherent set of events.
*/

#include <iostream>

using namespace std;
int main()
{ int day=0;
   cout<<"no. elements";
   int n,i,j;
   cin>>n;
   int a[40];
   cout<<"elements"<<endl;
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }

int count1=0,pos;
int flag=0;
day++;
   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {//met the final statement
           if((a[i]>=0)&&(a[i]==(-a[j])))
           { flag=1;
            count1+=2;
            pos=j;
            int *count3 = new int[sizeof(int)*(j-1)];


    for(int u = i; u <=j; u++)
    {
        if(count3[a[i]] == 1)
          {
            flag=1;
          cout <<-1<<"new statement";
            exit(0);  }
        else
           {
              count3[a[i]]++;
           }
    }
            break;
           }
           if(a[i]==a[j])
           {
        //find way for repetition solving
               if(pos<j)
               {    if(flag==1) break;
                   cout<<count1<<" A ";
                   count1=0;
                   day++;
               }
               else{ flag=0;
               break;}
           }
       }

   }
    if(flag==0)
       {
           //no went home

           cout<<-1;
           cout<<"hi2";
           exit(0);
       }
       else
       {
            cout<<"day"<<day<<endl;
            cout<<count1<<"B";
}
}

