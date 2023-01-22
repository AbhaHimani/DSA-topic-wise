#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
int n, m;
vector<int> findDataLocations(vector<int> locations, vector<int> movedFrom, vector<int> movedTo)
{
   unordered_map<int, int> mp;
   for (int i = 0; i < m; i++)
   {

      mp[movedFrom[i]] = movedTo[i];
   }

   for (int i = 0; i < n; i++)
   {

      if (mp.find(locations[i]) != mp.end() and mp[locations[i]] != -1)
      {

         int tar = mp[locations[i]];

         mp[locations[i]] = -1;

         while (mp.find(tar) != mp.end() and mp[tar] != -1)
         {
            tar = mp[tar];

            mp[tar] = -1;
         }

         locations[i] = tar;
      }
   }
   return locations;
}