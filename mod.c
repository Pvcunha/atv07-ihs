#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */
#include <linux/moduleparam.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pedro Cunha");

static int myint = 1;

static int __init hello_start(void)
{
    printk(KERN_ALERT "Loading hello module...\n");
    printk(KERN_ALERT "Hello world\n");
    return 0;
}

static void __exit hello_end(void)
{
    printk(KERN_ALERT "Goodbye Mr. parameter=%d\n", myint);
}

module_param(myint, int, 0);
module_init(hello_start);
module_exit(hello_end);
