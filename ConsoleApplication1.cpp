// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	while (true) 
	{
		cout << "Android Phone Tools" << endl;
		cout << "请选择操作：" << endl;
		cout << "1.adb推送指定文件（无需mtp）" << "/n" << "2.adb推送指定文件（无需mtp）" << endl;
		cout << "请输入数字选择：";
		string changeact;
		cin >> changeact;
		int cactnum;
		cactnum = stoi(changeact);
		//这里没校验str

		if (cactnum == 1)
		{
			string adb_push_address_local, adb_push_address_device, adb_push_address_cmdline;
			//adb推送文件变量
			bool step_0, step_1;
			step_0 = true;
			step_1 = true;
			system("cls");
			while (step_0)
			{
				while (step_1)
				{
					cout << "输入本地文件路径（可拖拽文件至此处）：";
					cin >> adb_push_address_local;
					if (adb_push_address_local.empty())
					{
						cout << "你没有输入任何地址！";
						system("cls");
					}
					else
					{
						step_1 = false;
					}
				}
				cout << "输入设备目标路径（不输入默认/sdcard目录）：";
				cin >> adb_push_address_device;
				if (adb_push_address_device.empty())
				{
					adb_push_address_device = "/sdcard/";
				}
				adb_push_address_cmdline = "adb push " + adb_push_address_local + " " + adb_push_address_device;
				WinExec(adb_push_address_cmdline.c_str(), SW_HIDE);
				step_0 = false;
			}

		}
		if (cactnum == 2)
		{
			string adb_pull_address_local, adb_pull_address_device, adb_pull_address_cmdline;
			//adb拉取文件变量
			bool step_0, step_1, step_2;
			step_0 = true;
			step_1 = true;
			step_2 = true;
			system("cls");
			while (step_0)
			{
				while (step_1)
				{
					cout << "输入设备文件路径：";
					cin >> adb_pull_address_device;
					if (adb_pull_address_device.empty())
					{
						cout << "你没有输入任何地址！";
						system("cls");
					}
					else
					{
						step_1 = false;
					}
				}
				while (step_2)
				{
					cout << "输入本地目标路径（不要磁盘根目录，除非使用管理员权限运行！）：";
					cin >> adb_pull_address_local;
					if (adb_pull_address_local.empty())
					{
						cout << "你没有输入任何地址！";
						system("cls");
					}
					else
					{
						step_2 = false;
					}
				}
				adb_pull_address_cmdline = "adb pull " + adb_pull_address_device + " " + adb_pull_address_local;
				WinExec(adb_pull_address_cmdline.c_str(), SW_HIDE);
				step_0 = false;
				Sleep(1500);
				system("cls");
			}
		}
		else
		{
			system("cls");
		}
	}
}
