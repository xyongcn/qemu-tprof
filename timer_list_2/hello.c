#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/jiffies.h>

struct timer_list timer;

static void timer_handle(unsigned long arg)
{
mod_timer(&timer, jiffies + HZ);
printk(" I am in timer\n");
}

static int __init test_init(void)
{

init_timer(&timer);
timer.function = &timer_handle;
timer.expires = jiffies + HZ;
add_timer(&timer);

printk("-------- test start ----------\n");
return 0;
}

static void __exit test_exit(void)
{
del_timer(&timer);
printk("-------- test over ----------\n");
return;
}

MODULE_LICENSE("GPL");

module_init(test_init);
module_exit(test_exit);
