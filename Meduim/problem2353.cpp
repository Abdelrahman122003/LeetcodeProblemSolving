// first Solution
class FoodRatings {
using item=pair<int, string>;//(rating, food), (rating, cuisine)
public:
map<string, pair<int, string>>foodRate;
map<string, set<item>>container;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
       for(int i = 0;i < foods.size();i++)
       {
          foodRate[foods[i]] = {-ratings[i], cuisines[i]};
          container[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
      string cuisine = foodRate[food].second;
      int rate = foodRate[food].first;
      // delete food and his rate then add it again
        container[cuisine].erase({rate, food});
        container[cuisine].insert({-newRating, food});
      // change rate first
        foodRate[food].first = -newRating;
    }
    
    string highestRated(string cuisine) {
      return container[cuisine].begin()->second;
    }
};

// second Solution

class custom_comparator
{
    public: 
    bool operator() (const pair<string, int>& a, const pair<string, int>& b) const
    {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

class FoodRatings 
{
    public:

    // Hash Function : 
    // H1(food_name) = { cuisine_name, current_rating }

    unordered_map<string, pair<string, int>> food_info;

    // Hash Function : 
    // H2(cuisine_name) = SET({ food_name, current_rating } : ordered by current_rating DESCENDING)

    unordered_map<string, set<pair<string, int>, custom_comparator>> cuisine_info;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) // Time : 0(n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int n = (int) foods.size(); 

        for(int i = 0; i < n; ++i)
        {
            food_info[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_info[cuisines[i]].insert(make_pair(foods[i], ratings[i]));
        }
    }
    
    void changeRating(string food, int new_rating) // Time : 0(log N)
    {
        pair<string, int>& f = food_info[food];
        const string& cuisine = f.first;
        int old_rating = f.second;

         set<pair<string, int>, custom_comparator>& st = cuisine_info[cuisine];

        // Remove { food, old_rating } record from cuisine_info

        st.erase({food, old_rating});

        // Update new rating of the food in food_info and its cuisine_info

        f.second = new_rating;
        st.insert(make_pair(food, new_rating));
        

        return;
    }
    
    string highestRated(string cuisine) // Tine : 0(1)
    {
        return cuisine_info[cuisine].begin()->first;
    }
};