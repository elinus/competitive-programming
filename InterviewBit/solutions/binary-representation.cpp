string Solution::findDigitsInBinary(int A) {
    if (!A) return "0";
    string bin("");
    while(A) {
        int rem = A % 2;
        int quo = A / 2;
        A = quo;
        bin.append(to_string(rem));
    }
    string answer(bin.rbegin(), bin.rend());
    return answer;
}

