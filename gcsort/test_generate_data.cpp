#include "gcsort.h"
#include "generate_data.h"
#include "gtest/gtest.h"

TEST(generate_data, running1){
	int arrsize = 10;
	int top_max = 50;
	ASSERT_PRED2(generate_data, arrsize, top_max);
/*
	arrsize = -10;
	top_max = -50;
	EXPECT_PRED2(generate_data, arrsize, top_max);
*/

	ASSERT_GT(top_max, RANDOM(top_max));
	//ASSERT_GT(2, RANDOM(top_max))<< "RANDOM greater than test num !";


/*测试返回成功或失败情况*/
	//ADD_FAILURE() << "sorry, return error!!";//继续往下执行。
	//FAIL();//Fatal Assertion 不往下执行该测试。
	SUCCEED();
}
