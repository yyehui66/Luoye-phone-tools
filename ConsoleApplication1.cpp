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
		cout << "Pre-0.1.2" << endl;
		cout << "请选择操作：" << endl;
		cout << "0.退出此程序" << endl << "1.adb推送指定文件（无需mtp）" << endl << "2.adb拉取指定文件（无需mtp）" << endl << "3.设备重启(到...模式)" << endl;
		cout << "请输入数字选择：";
		string changeact;
		cin >> changeact;

		if (changeact == "1")
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
		if (changeact == "2")
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
		if (changeact == "3")
		{
			pdelse = false;
			string reboot_change;
			system("cls");
			cout << "选择如何重启：" << endl;
			cout << "0.正常重启" << endl;
			cout << "1.Fastboot(Bootloader)" << endl;
			cout << "2.FastbootD(Android 10以上)" << endl;
			cout << "3.Recovery)" << endl;
			cout << "4.EDL(部分机型)" << endl;
			cout << "输入其他内容退出" << endl;
			cin >> reboot_change;
			if (reboot_change == "0")
			{
				WinExec("adb reboot", SW_HIDE);
			}
			if (reboot_change == "1")
			{
				WinExec("adb reboot bootloader", SW_HIDE);
			}
			if (reboot_change == "2")
			{
				WinExec("adb reboot fastboot", SW_HIDE);
			}
			if (reboot_change == "3")
			{
				WinExec("adb reboot recovery", SW_HIDE);
			}
			if (reboot_change == "4")
			{
				WinExec("adb reboot edl", SW_HIDE);
			}
			else
			{
				system("cls");
			}
		}
		if (changeact == "0")
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
