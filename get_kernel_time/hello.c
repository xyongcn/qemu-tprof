#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h> /*kmalloc*/
#include <asm/msr.h>  /*native_read_tsc*/
#include<linux/time.h> /*struct timespec*/
#include<linux/delay.h> /*udelay macro */
#include <linux/fs.h>  
#include <asm/uaccess.h>




extern void getnstimeofday(struct timespec *ts);
//extern  unsigned long jiffies;
MODULE_LICENSE("GPL");



static int __init hello3_init(void)
{
   unsigned long long * t_tsc;
   struct timespec * t_now;
   unsigned long * t_jiffies;
   int i=0;
   t_tsc= (unsigned long long *)kmalloc(4000*sizeof(unsigned long long),GFP_ATOMIC);
   t_now= (struct timespec *)kmalloc(4000*sizeof(struct timespec),GFP_ATOMIC);   
   t_jiffies= (unsigned long *)kmalloc(4000*sizeof(unsigned long),GFP_ATOMIC);
//   printk("aaa:%d,%d\n",4000*sizeof(unsigned long long),4000*sizeof(struct timespec));
//   printk("bbb:%d,%d\n",sizeof(t_tsc),sizeof(t_now)); 

  
   for(i=0; i<4000; i++)
   {
   
   t_tsc[i]= __native_read_tsc(); /*read tsc */
   getnstimeofday(&t_now[i]);     /*read second ,nanosecond from 1970.1.1*/   
   t_jiffies[i]=jiffies;          /*jiffies since from power on ,usually 1 jiffy=1/250 second*/
//   printk("i:%d\n",i);
//   printk("t_tsc:%llu\n",t_tsc[i]);
//   printk("t_now:%lu,%lu\n",t_now[i].tv_sec,t_now[i].tv_nsec);
//   printk("t_jiffies:%lu\n",t_jiffies[i]);

   mdelay(10);  /*delay 10 milisecond*/
   } 
   printk("jin ru\n");    


/*write file*/
   mm_segment_t old_fs;
   struct file *fp = NULL;



   fp = filp_open("/home/result.txt",O_RDWR | O_CREAT, 0644);
   if(fp)
   {
       old_fs = get_fs();
       set_fs(get_ds());
        //      fp->f_op->write(fp,m_buffer1,sizeof(m_buffer1),&fp->f_pos);
        //      fp->f_op->write(fp,m_buffer2,sizeof(m_buffer1),&fp->f_pos);
         vfs_write(fp,(unsigned char *)t_tsc,4000*sizeof(unsigned long long),&fp->f_pos);
         vfs_write(fp,(unsigned char *)t_now,4000*sizeof(struct timespec),&fp->f_pos);
         vfs_write(fp,(unsigned char *)t_jiffies,4000*sizeof(unsigned long),&fp->f_pos);
        set_fs(old_fs);
       filp_close(fp,NULL);
        printk("success \n");
   }
 else
    {
        printk("Can't open ~/result.txt\r\n");
    }

   return 0; 

}

module_init(hello3_init);






static void __exit hello3_exit(void)
{
   
   printk("tui chu\n");    
}



module_exit(hello3_exit);
