/******************************************************************************
 * @file    : ipmac_driver.c
 * @Author  : Adish M R
 * @Question: Linux Character Device driver which displays the MAC address and
 *            ip address of wlan0 and eth0 interface in kernel log
 *****************************************************************************/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/inetdevice.h> 
#include <net/net_namespace.h>
#define SUCCESS 0


static dev_t first; /*first device number*/
struct net_device *dev;
struct in_device* in_dev;
struct in_ifaddr* if_info;
int ret = 0, i;
__u8 *addr;

/* Constructor */
static int __init chardrvr_init(void) {
    printk(KERN_INFO "IPMAC: registered\n");
    if ((ret = alloc_chrdev_region(&first, 0, 1, "Adish")) < 0){
        return ret;
    }
    dev = __dev_get_by_name(&init_net,"wlan0");
    for (i = 0; i<2; i++) {
    printk("HWaddr: %pM\n",dev->dev_addr); /*printing MAC addr*/
    in_dev = (struct in_device *)dev->ip_ptr;
  	if_info = in_dev->ifa_list;
  	addr = (char *)&if_info->ifa_local;
  	printk(KERN_INFO "inet addr: %u.%u.%u.%u\n", 
          (__u32)addr[0], 
          (__u32)addr[1], 
          (__u32)addr[2], 
          (__u32)addr[3]); 
    dev = __dev_get_by_name(&init_net,"eth0");
    }
    return SUCCESS;
}

/* Destructor */
static void __exit chardrvr_exit(void) {
    unregister_chrdev_region(first, 1);
    printk(KERN_INFO "IPMAC: unregistered\n");
}

module_init(chardrvr_init);
module_exit(chardrvr_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Adish M R");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("This Driver displays the IP addr and MAC addr");
