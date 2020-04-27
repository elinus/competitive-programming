vector<int> Solution::allFactors(int A) {
    vector<int> fact;
    for (int i=1; i<=sqrt(A); i++) 
    { 
        if (A%i == 0) 
        { 

            if (A/i == i) 
                fact.push_back(i); 
            else {
                fact.push_back(i); 
                fact.push_back(A/i);
            }
        } 
    } 
    sort(fact.begin(), fact.end());
    return fact;
}

