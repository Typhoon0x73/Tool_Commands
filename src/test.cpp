#include <iostream>
#include "CommandManager.h"

#include "ChangeCommand/ChangeCommand.h"
#include "SwapCommand/SwapCommand.h"
#include <vector>

void print(std::string_view str) {
	std::cout << str << std::endl;
}

void print(std::vector<std::int32_t>& v) {
	for (const auto& s : v)
	{
		std::cout << std::to_string(s) << ", ";
	}
	std::cout << std::endl;
}

void test_func() {
	using namespace sip;
	bool is_success = false;
	CommandManager cmd_mng;

	std::vector<std::int32_t> nums = { 10, 20, 30, 40, 50 };
	std::int64_t num = 100;
	std::string  str = "abcde";
	print(str);
	auto num_change_cmd = std::make_unique<ChangeS64Command>(&num, 4000);
	auto str_change_cmd = std::make_unique<ChangeStringCommand>(&str, "fghij");
	auto num_swap_cmd   = std::make_unique<SwapCommand<std::int32_t>>(&nums[2], &nums[1]);
	is_success = cmd_mng.regist(std::move(str_change_cmd));
	print(is_success ? "success" : "failed");
	print(str);
	is_success = cmd_mng.undo();
	print(is_success ? "success" : "failed");
	print(str);
	is_success = cmd_mng.redo();
	print(is_success ? "success" : "failed");
	print(str);
	is_success = cmd_mng.undo();
	print(is_success ? "success" : "failed");
	print(str);
	cmd_mng.clear();
	is_success = cmd_mng.redo();
	print(is_success ? "success" : "failed");
	print(str);
	is_success = cmd_mng.regist(std::move(num_change_cmd));
	print(is_success ? "success" : "failed");
	print(std::to_string(num));
	is_success = cmd_mng.undo();
	print(is_success ? "success" : "failed");
	print(std::to_string(num));
	is_success = cmd_mng.redo();
	print(is_success ? "success" : "failed");
	print(std::to_string(num));
	is_success = cmd_mng.undo();
	print(is_success ? "success" : "failed");
	print(std::to_string(num));
	cmd_mng.clear();
	is_success = cmd_mng.redo();
	print(is_success ? "success" : "failed");
	print(std::to_string(num));
	is_success = cmd_mng.regist(std::move(num_swap_cmd));
	print(is_success ? "success" : "failed");
	print(nums);
	is_success = cmd_mng.undo();
	print(is_success ? "success" : "failed");
	print(nums);
	is_success = cmd_mng.redo();
	print(is_success ? "success" : "failed");
	print(nums);
	is_success = cmd_mng.regist(std::move(std::make_unique<SwapCommand<std::int32_t>>(&nums[4], &nums[2])));
	print(is_success ? "success" : "failed");
	print(nums);
	is_success = cmd_mng.undo();
	print(is_success ? "success" : "failed");
	print(nums);
	is_success = cmd_mng.undo();
	print(is_success ? "success" : "failed");
	print(nums);
}

int main(int argc, char** argv) {
	test_func();
	return 0;
}