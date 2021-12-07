#include <gtest/gtest.h>

#include <string_view>

TEST(hellotests, helloworld)
{
    std::string_view var{ "helloworld" };
    ASSERT_STREQ(var.data(), "helloworld");
}