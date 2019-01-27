class Solution {
public:
    string numberToWords(int num) {
        string unit[] = {"",
                    "One",
                    "Two",
                    "Three",
                    "Four",
                    "Five",
                    "Six",
                    "Seven",
                    "Eight",
                    "Nine"};
        string tens[] = {"",
                        "Ten",
                        "Twenty",
                        "Thirty",
                        "Forty",
                        "Fifty",
                        "Sixty",
                        "Seventy",
                        "Eighty",
                        "Ninety",
                        };
        string exceptionalTens[] = {"Ten",
                                    "Eleven",
                                   "Twelve",
                                   "Thirteen",
                                   "Fourteen",
                                   "Fifteen",
                                   "Sixteen",
                                   "Seventeen",
                                   "Eighteen",
                                   "Nineteen"};
        string level[] = {"",
                        "Thousand",
                         "Million",
                         "Billion"};
        string ans="", temp="";
        int count=0;
        int l=0, last, m;
        while(num!=0)
        {
            int d = num%10;
            num=num/10;
            m=count%3;
            count++;
            if(m==0 && d!=0)
            {
                temp=" "+unit[d];
            }
            else if(m==1 && d!=0)
            {
                if(d!=1)
                {
                    temp=" "+tens[d]+temp;
                }
                else
                {
                    temp=" " + exceptionalTens[last];
                }
            }
            else if(m==2)
            {
                if(d!=0)
                {
                    temp=" "+unit[d]+" Hundred"+temp;
                }
                if(temp!="" && l>0)
                {
                    temp=temp+" "+level[l];
                }
                ans = temp + ans;
                l++;
                temp="";
            }
            last=d;
        }
        if(m!=2)
        {
            if(temp!="" && l>0)
            {
                temp=temp+" "+level[l];
            }
            ans = temp + ans;
        }
        if(ans=="")
            return "Zero";
        string a="";
        for(int i=1;i!=ans.length(); i++)
        {
            a+=ans[i];
        }
        return a;
    }
};