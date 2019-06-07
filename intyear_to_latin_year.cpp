#include <iostream>
#include <sstream>
#include <string>

using std::cerr, std::cout, std::endl, std::stringstream, std::string, std::stoi;

// TODO: test it via: https://www.calculatorsoup.com/calculators/conversions/roman-numeral-converter.php
// NOTE: there are invalid combinations? (eg. 1500 is MD not MDM  huh??)
//
// examples:
//   1498 = MCDXCVIII
//   1998 = MCMXCVIII
//   2498 = MMCDXCVIII

// aw, snap!
// see:  http://news.bbc.co.uk/1/hi/245709.stm
// They cannot agree whether it should be the snappy MIM or a more unwieldy MCMXCIX.
// 
// A standard usage is important for publishers, film-makers, and many others who use Roman numerals to stamp copyright on their work.
// 
// The long form translates as one thousand nine-hundred and ninety nine - or 1,000, plus 1000 minus 100, plus 100 minus 10, plus 10 minus one.
// 
// The shorter equivalent of MIM means two thousand minus one. The BBC has chosen the longer version. The year 2000 will be MM.
// 
// Others who will have to make up their mind include Pope John Paul II, film director Stephen Spielberg as he puts the finishing touches to his latest movie, American football superbowl which also uses Roman numbers and the Finnish radio station which broadcasts in Latin.
// 
// Roman numerals use letters in place of numbers: M = 1,000, D = 500, C = 100, L=50, X = 10, V = 5, and I = 1.
// 
// A number placed before a larger one can have the effect of minus - thus IV is four, five minus one, athough it is also often written as IIII.
//
//

// 1, 5, 10, 50, 100, 500, 1000 ???
// enum LatinDigits {
//   I, V, X, L, C, D, M
// };

void print_latin_year(const char*);
string do_it(int);
string convert_digit(int, const char*, const char*, const char*);

int main(int argc, const char* argv[]) {
  for (int i=1; i<argc; ++i) {
    print_latin_year(argv[i]);
  }
  return 0;
}

void print_latin_year(const char* intnum) {
  int decimal_year = stoi(intnum);

  if (decimal_year < 0 || decimal_year > 3999) {
    cout << "Please give year in range [0, 3999]" << endl;
    return;
  }

  string hach_year = do_it(decimal_year);
  cout << "Year: " << decimal_year << " as latin year: " << hach_year << endl;
}

string do_it(int decimal) {
  int thousands = decimal / 1000;
  decimal %= 1000;
  int cent = decimal / 100;
  decimal %= 100;
  int tenth = decimal / 10;
  int oneth = decimal % 10;

  stringstream s;
  // s << thousands << " * 1000 + " << cent << " * 100 + " << tenth << " * 10 + " << oneth;
  string lThousands = convert_digit(thousands, "M", NULL, NULL);
  string lCenturies = convert_digit(thousands, "C", "D", "M");
  string lDecades = convert_digit(thousands, "X", "L", "C");
  string lYears = convert_digit(oneth, "I", "X", "V");
  s << lThousands << lCenturies << lDecades << lYears;
  return s.str();
}

string convert_digit(int digit, const char* oneDigit, const char* tenDigit, const char* fiveDigit) {
  if (digit < 1 || digit > 9 || (tenDigit == NULL && digit > 3)) { // can't do that
    return "";
  }
  stringstream s;
  switch (digit) {
    case 9:
      s << oneDigit << tenDigit;
      break;
    case 8:
      s << fiveDigit << oneDigit << oneDigit << oneDigit;
      break;
    case 7:
      s << fiveDigit << oneDigit << oneDigit;
      break;
    case 6:
      s << fiveDigit << oneDigit;
      break;
    case 5:
      s << fiveDigit;
      break;
    case 4:
      s << oneDigit << fiveDigit;
      break;
    case 3:
      s << oneDigit << oneDigit << oneDigit;
      break;
    case 2:
      s << oneDigit << oneDigit;
      break;
    case 1:
      s << oneDigit;
      break;
    default: // riesen error
      cerr << "unexpected. should not reach..." << endl;
  };
  return s.str();
}
