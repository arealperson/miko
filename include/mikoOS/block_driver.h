#ifndef __MIKOOS_BLOCK_DRIVER_H
#define __MIKOOS_BLOCK_DRIVER_H 1

struct blk_dev_driver_operations {
	char name[32]; // driver name.
	int (*open)(void);
	int (*close)(void); // temporary definition.
	int (*read)(void); // temporary definition.
	int (*write)(void); // temporary definition.
	int (*ioctl)(void); // temporary definition.
	int (*scattered_io)(void); // temporary definition.
};

struct blk_device_drivers {
	struct blk_dev_driver_operations *op;
	struct blk_device_drivers *next;
};

void register_blk_driver(struct blk_dev_driver_operations *op);
void remove_blk_driver(struct blk_dev_driver_operations *op);
void show_all_registered_driver(void);

#endif // __MIKOOS_BLOCK_DRIVER_H