/*
You are given an array strarr of strings and an integer k. Your task is to return the first longest string consisting of k consecutive strings taken in the array.

Example:
longest_consec(["zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"], 2) --> "abigailtheta"

n being the length of the string array, if n = 0 or k > n or k <= 0 return "".

Note
consecutive strings : follow one after another without an interruption
*/

#include <string>
#include <vector>

class LongestConsec
{
public:

	static std::string longestConsec(std::vector<std::string> &strarr, int k) {
		std::string strbuffer = "";
		std::string stranswer = "";
		int count = 0;

		for (int i = 0; i < strarr.size(); ++i) {

			if ((i + k) <= strarr.size()) {

				for (int j = i; j < (i + k); ++j) {
					strbuffer += strarr[j];
				}
			}
			else {

			}

				if (strbuffer.size() > stranswer.size()) { 
					stranswer = strbuffer; 
					strbuffer = "";
					count = 0; 
				}
				else {
					strbuffer = "";
					count = 0;
				}
			

		}

		return stranswer;
	}

};




//Other Answers
//___________________________________________________________________________________________________________//
#include <functional>
#include <numeric>
#include <string>
#include <vector>

class LongestConsec {
public:
	static std::string longestConsec(const std::vector<std::string>& strings, int k) {
		k = std::max(k, 0);
		std::string longest;
		for (size_t i = k; i <= strings.size(); i += 1) {
			auto begin = std::next(strings.begin(), i - k);
			auto end = std::next(begin, k);
			std::string s = std::accumulate(begin, end, std::string());
			if (s.length() > longest.length()) {
				longest = s;
			}
		}
		return longest;
	}
};
//___________________________________________________________________________________________________________//
#include <string>
#include <vector>
#include <numeric>
class LongestConsec
{
public:
	static std::string longestConsec(std::vector<std::string>& a, int k) {
		if (a.empty() || k > a.size() || k <= 0) return "";
		std::string best;
		for (std::size_t i = 0; i + k <= a.size(); ++i) {
			auto consec = std::accumulate(a.begin() + i, a.begin() + i + k, std::string());
			if (consec.size() > best.size()) best = consec;
		}
		return best;
	}
};
//___________________________________________________________________________________________________________//

//___________________________________________________________________________________________________________//

//___________________________________________________________________________________________________________//