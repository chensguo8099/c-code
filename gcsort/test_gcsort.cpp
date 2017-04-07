#include "gcsort.h"
#include "generate_data.h"
#include "gtest/gtest.h"

TEST(test_compar_num, running2){
	int a = 46, b = 47;
	//ASSERT_PRED2(compar_num, a, b);
	int rand_num = RANDOM(a);
	if(rand_num < b)
		ASSERT_EQ(-1, compar_num(&rand_num, &b));
	else
		FAIL();//test compar_num function

	//EXPECT_TURE(compar_num(20, 47));
	SUCCEED();
}
