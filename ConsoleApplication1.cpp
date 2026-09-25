//by leavesyh
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	bool pdelse = true;
	while (true)
	{
		pdelse = true;
		cout << "落叶手机工具箱		by leavesyyh" << endl;
		cout << "Pre-0.1.1" << endl;
		cout << "请选择操作：" << endl;
		cout << "0.退出此程序" << endl << "1.adb推送指定文件（无需mtp）" << endl << "2.adb拉取指定文件（无需mtp）" << endl << "3.设备重启" << endl << "4.设备重启Fastboot(Bootloader)" << endl << "5.设备重启至FastbootD(需要Android 10及以上版本)" << endl << "6.设备重启至Recovery" << endl << "7.设备重启至edl(部分旧设备可以)" << endl;
		cout << "请输入数字选择：";
		string changeact;
		cin >> changeact;
		int cactnum;

		try
		{
			cactnum = stoi(changeact);
		}
		catch (const invalid_argument)
		{
			pdelse = false;
			cout << "非正常数字字符，请重新输入";
			Sleep(1500);
			system("cls");
		}
		catch (const out_of_range)
		{
			pdelse = false;
			cout << "数字超出范围，请重新输入";
			Sleep(1500);
			system("cls");
		}
		catch (...)
		{
			printf("异常错误！");
			cout << endl;
			cout << "code:-1";
			return -1;
		}

		if (cactnum == 1)
		{
			pdelse = false;
			string adb_push_address_local, adb_push_address_device, adb_push_address_cmdline;
			//adb推送文件变量
			system("cls");


			cout << "输入本地文件路径（可拖拽文件至此处）：";
			cin >> adb_push_address_local;
			cout << "输入设备目标路径（输入默认1目录）：";
			cin >> adb_push_address_device;
			if (adb_push_address_device == "1")
			{
				adb_push_address_device = "/sdcard/";
			}
			adb_push_address_cmdline = "adb push " + adb_push_address_local + " " + adb_push_address_device;
			WinExec(adb_push_address_cmdline.c_str(), SW_HIDE);
			Sleep(1500);
			system("cls");


		}
		if (cactnum == 2)
		{
			pdelse = false;
			string adb_pull_address_local, adb_pull_address_device, adb_pull_address_cmdline;
			//adb拉取文件变量
			system("cls");
			cout << "输入设备文件路径：";
			cin >> adb_pull_address_device;
			cout << "输入本地目标路径（不要磁盘根目录，除非使用管理员权限运行！）：";
			cin >> adb_pull_address_local;
			adb_pull_address_cmdline = "adb pull " + adb_pull_address_device + " " + adb_pull_address_local;
			WinExec(adb_pull_address_cmdline.c_str(), SW_HIDE);
			Sleep(1500);
			system("cls");

		}
		if (cactnum == 3)
		{
			pdelse = false;
			WinExec("adb reboot", SW_HIDE);
		}
		if (cactnum == 4)
		{
			pdelse = false;
			WinExec("adb reboot bootloader", SW_HIDE);
		}
		if (cactnum == 5)
		{
			pdelse = false;
			WinExec("adb reboot fastboot", SW_HIDE);
		}
		if (cactnum == 6)
		{
			pdelse = false;
			WinExec("adb reboot recovery", SW_HIDE);
		}
		if (cactnum == 7)
		{
			pdelse = false;
			WinExec("adb reboot edl", SW_HIDE);
		}
		if (cactnum == 0)
		{
			pdelse = false;
			cout << "此程序将在3s后退出...";
			Sleep(3000);
			return 0;
		}
		if (pdelse)
		{
			cout << "不是已有的功能，请重新输入";
			Sleep(1500);
			system("cls");
		}
	}
}
