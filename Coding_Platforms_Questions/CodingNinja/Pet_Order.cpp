#include <bits/stdc++.h>

vector<int> findOrder(vector<vector<int>> arr, int n)

{

    // Write Your Code here

    queue<pair<int, int>> dog, cat;

    vector<int> res;

    for (int i = 0; i < n; i++)

    {

        vector<int> v = arr[i];

        if (v.size() == 3)

        {

            // brought

            int id = v[1];

            int type = v[2];

            if (type == 0)

                dog.push({id, i});

            else

                cat.push({id, i});
        }

        else

        {

            // sell

            int type = v[1];

            if (type == 0 and dog.size() > 0)

            {

                res.push_back(dog.front().first);

                dog.pop();
            }

            else if (type == 1 and cat.size() > 0)
            {

                res.push_back(cat.front().first);

                cat.pop();
            }

            else

            {

                if (cat.size() == 0)

                {

                    res.push_back(dog.front().first);

                    dog.pop();
                }

                else if (dog.size() == 0)
                {

                    res.push_back(cat.front().first);

                    cat.pop();
                }
                else

                {

                    auto d = dog.front(), c = cat.front();

                    if (d.second > c.second)

                    {

                        res.push_back(c.first);

                        cat.pop();
                    }
                    else

                    {

                        res.push_back(d.first);

                        dog.pop();
                    }
                }
            }
        }
    }

    return res;
}