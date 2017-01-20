// ==============================================================
//
//  Copyright (C) 2004-2016  Alex Vinokur.
//
//  ------------------------------------------------------------
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//  ------------------------------------------------------------
//
//  mailto:alex DOT vinokur AT gmail DOT com
//  http://sourceforge.net/users/alexvn/
//
// ==============================================================


// ##############################################################
//
//  SOFTWARE : Class BigInt
//  FILE     : main.cpp
//
//  DESCRIPTION :
//          Nain program
//
// ##############################################################


// ===============
#include "bigInt.h"
#include <time.h>
// ===============

// --------------------

std::string current_time(){
    time_t now = time(NULL);
    struct tm tstruct;
    char buf[40];
    tstruct = *localtime(&now);
    //format: HH:mm:ss
    strftime(buf, sizeof(buf), "%X", &tstruct);
    return buf;
}

static void simpleDemoBigInt (std::ostream& o_stream)
{

    SET_START_TEST_NAME(o_stream);

#define SHOW_BIG_INT(x) o_stream << #x << " : Hex Value = " << x.toStr0xHex() << ", Hex Digits = " << x.getActualHexDigits() << "; Dec Value = " << x.toStrDec() << ", Dec Digits = " << x.getActualDecDigits() << std::endl << std::endl
#define SHOW_DOUBLE(x)  o_stream << #x << " : " << std::fixed << x << std::endl << std::endl

    BigInt::Rossi n1 ("314159265358979323846264338327950288419716939937510", BigInt::DEC_DIGIT);
    SHOW_BIG_INT(n1);

    BigInt::Rossi n2 ("224f3e07282886cce82404b6f8", BigInt::HEX_DIGIT);
    SHOW_BIG_INT(n2);

    BigInt::Rossi n3 (1123);
    SHOW_BIG_INT(n3);

    BigInt::Rossi n4 = n1 + n2;
    SHOW_BIG_INT(n4);

    BigInt::Rossi n5 = n1 * n3;
    SHOW_BIG_INT(n5);

    BigInt::Rossi n6 = n2 / n3;
    SHOW_BIG_INT(n6);

    BigInt::Rossi n7 = n1.sqrt();
    SHOW_BIG_INT(n7);

    BigInt::Rossi n8 = BigInt::Rossi::pow (n1, n3);
    SHOW_BIG_INT(n8);

    long double d1 = n1.toDouble();
    SHOW_DOUBLE(d1);

    long double d2 = 1123581321345589144233.0;
    SHOW_DOUBLE(d2);

    BigInt::Rossi n9 = BigInt::Rossi::fromDouble(d2);
    SHOW_BIG_INT(n9);

#undef SHOW_BIG_INT
#undef SHOW_DOUBLE

    // --------------------------
    SET_FINISH_TEST_NAME(o_stream);

    o_stream << std::endl;
    o_stream << std::endl;
    o_stream << std::endl;
    o_stream << std::endl;

}


// --------------------
static void demoBigInt (std::ostream& o_stream, const std::string& i_exeFileName)
{
    std::ostringstream oss;

    SET_START_TEST_NAME(oss);

    BigInt::Rossi arg1 (100);
    BigInt::Rossi arg2 ("123456789", BigInt::DEC_DIGIT);
    BigInt::Rossi arg3 ("123456789ABCDEF0FEDCBA321", BigInt::HEX_DIGIT);

    BigInt::Rossi result;

    // --------------------------------------------
    result = arg1 + arg2;
    oss << "[Hex] " << arg1 << " + " << arg2 << " = " << result << std::endl;
    oss << "[Dec] " << arg1.toStrDec() << " + " << arg2.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg1 + arg3;
    oss << "[Hex] " << arg1 << " + " << arg3 << " = " << result << std::endl;
    oss << "[Dec] " << arg1.toStrDec() << " + " << arg3.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg2 + arg3;
    oss << "[Hex] " << arg2 << " + " << arg3 << " = " << result << std::endl;
    oss << "[Dec] " << arg2.toStrDec() << " + " << arg3.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;


    // --------------------------------------------
    result = arg2 / arg1;
    oss << "[Hex] " << arg2 << " / " << arg1 << " = " << result << std::endl;
    oss << "[Dec] " << arg2.toStrDec() << " / " << arg1.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg3 / arg1;
    oss << "[Hex] " << arg3 << " / " << arg1 << " = " << result << std::endl;
    oss << "[Dec] " << arg3.toStrDec() << " / " << arg1.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg3 / arg2;
    oss << "[Hex] " << arg3 << " / " << arg2 << " = " << result << std::endl;
    oss << "[Dec] " << arg3.toStrDec() << " / " << arg2.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;


    // --------------------------------------------
    result = arg1 * arg2;
    oss << "[Hex] " << arg1 << " * " << arg2 << " = " << result << std::endl;
    oss << "[Dec] " << arg1.toStrDec() << " * " << arg2.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg1 * arg3;
    oss << "[Hex] " << arg1 << " * " << arg3 << " = " << result << std::endl;
    oss << "[Dec] " << arg1.toStrDec() << " * " << arg3.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg2 * arg3;
    oss << "[Hex] " << arg2 << " * " << arg3 << " = " << result << std::endl;
    oss << "[Dec] " << arg2.toStrDec() << " * " << arg3.toStrDec() << " = " << result.toStrDec() << std::endl;
    oss << std::endl;

    // --------------------------------------------
    result = arg1.sqrt();
    oss << "[Hex] " << arg1 << ".sqrt() = " << result << std::endl;
    oss << "[Dec] " << arg1.toStrDec() << ".sqrt() = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg2.sqrt();
    oss << "[Hex] " << arg2 << ".sqrt() = " << result << std::endl;
    oss << "[Dec] " << arg2.toStrDec() << ".sqrt() = " << result.toStrDec() << std::endl;
    oss << std::endl;

    result = arg3.sqrt();
    oss << "[Hex] " << arg3 << ".sqrt() = " << result << std::endl;
    oss << "[Dec] " << arg3.toStrDec() << ".sqrt() = " << result.toStrDec() << std::endl;
    oss << std::endl;


    // --------------------------
    SET_FINISH_TEST_NAME(oss);

    oss << std::endl;
    oss << std::endl;
    oss << std::endl;
    BigInt::Run::showHelp(oss, i_exeFileName);

    o_stream << oss.str() << std::endl;
}


// --------------------
static void showIllegalCommandLineBigInt (std::ostream& o_stream, int argc, char** argv)
{
    std::ostringstream oss;

    oss << ""

        << std::endl
        << "\t"
        << "===> ILLEGAL INPUT <==="
        << std::endl
        << std::endl;

    BigInt::Run::showCommandLine (oss, argc, argv);
    BigInt::Run::showHelp(oss, argv[0]);

    o_stream << oss.str() << std::endl;
}

bool czy_pierwsza(BigInt::Rossi n)
{
    BigInt::Rossi i(2);
    BigInt::Rossi zero(0);

//    std::cout << "i : "<< i.toStrDec()<<std::endl;
//    std::cout << "zero : "<< zero.toStrDec()<<std::endl;
//    std::cout << "n : "<< n.toStrDec()<<std::endl;
    if(n<i)
        return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

    for(  BigInt::Rossi i(2)  ;i*i<=n; i++){

        if(n%i==zero){

            return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
        }
    }
    return true;
}

// ===================
int main (int argc, char** argv)
{
    //    BigInt::Run::showTime (std::cout, "START");
    //    BigInt::Run::showCommandLine (std::cout, argc, argv);

    //    std::string flag;

    //    if (argc == 1)
    //    {
    //        flag = BigInt::s_strHelp;
    //    }
    //    else
    //    {
    //        flag = argv[1];
    //    }


    //    if ((argc <= 2) && (flag == BigInt::s_strHelp))
    //    {
    //        BigInt::Run::showHelp(std::cout, argv[0]);
    //        BigInt::Run::showTime (std::cout, "FINISH showHelp()");
    //        return 0;
    //    }

    //    if ((argc == 2) && (flag == BigInt::s_strDemo))
    //    {
    //        simpleDemoBigInt(std::cout);
    //        demoBigInt(std::cout, argv[0]);
    //        BigInt::Run::showTime (std::cout, "FINISH demoBigInt()");
    //        return 0;
    //    }

    //    if (
    //            ((argc == 2) && (flag == BigInt::s_strTest))
    //            ||
    //            (argc == 4)
    //        )
    //    {
    //        const int result = BigInt::Run::mainBigInt(argc, argv);
    //        BigInt::Run::showTime (std::cout, "FINISH testBigInt()");
    //        return result;
    //    }

    //    if ((argc == 2) && (flag == BigInt::s_strTime))
    //    {
    //        BigInt::Run::mainBigInt(argc, argv);
    //        BigInt::Run::showTime (std::cout, "FINISH performanceTestBigInt()");
    //        return static_cast<int>(BigInt::Test::s_returnValue);
    //    }



    //    showIllegalCommandLineBigInt (std::cout, argc, argv);
    //    BigInt::Run::showTime (std::cout, "FINISH showIllegalCommandLineBigInt()");

    BigInt::Rossi n1 ("123456789123456789", BigInt::DEC_DIGIT);
    BigInt::Rossi n2 ("1234567891234567891", BigInt::DEC_DIGIT);
    BigInt::Rossi n3 =  n1*n2+n2+1;
    std::cout << "duza liczba =suma : "<< n3.toStrDec()<<std::endl;

    int i = 0;
    int k = 100000;


    while ( true)
    {
        if (n1 > n2){
            std::cout <<" koniec albo zle dane" <<std::endl;
            break;
        }
        if (czy_pierwsza(++n1) == true){
            std::cout << "Liczba pierwsza: "<< n1.toStrDec() << " wynik "<< ++i<< std::endl;
        }
        std::cout << "nastepna "<<++i << " time: "<< current_time()<<std::endl;
    }
    return 0;
}


