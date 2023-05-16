#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/keyboard.h>
static struct notifier_block keyboard_notifier;
static int keyboard_event(struct notifier_block *nb, unsigned long event, void *data)
{
    struct keyboard_notifier_param *param = data;
    if (event == KBD_KEYCODE)
    {
pr_info("Keyboard Event: keycode = %d, value = %d, down
= %d\n", param->value, param->down, param->down ? 1 : 0);
    }
    return NOTIFY_OK;
}
static int __init keyboard_io_init(void)
{
    pr_info("Keyboard I/O Module: Initializing\n");
    keyboard_notifier.notifier_call = keyboard_event;
    register_keyboard_notifier(&keyboard_notifier);
    return 0;
}
static void __exit keyboard_io_exit(void)
{
    pr_info("Keyboard I/O Module: Exiting\n");
    unregister_keyboard_notifier(&keyboard_notifier);
}
module_init(keyboard_io_init);
module_exit(keyboard_io_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Keyboard I/O Module");