    #include <iostream> //标准输入输出流  
    #include <pcl/io/pcd_io.h> //PCL的PCD格式文件的输入输出头文件  
    #include <pcl/point_types.h> //PCL对各种格式的点的支持头文件  
    #include <pcl/visualization/cloud_viewer.h>  
      
    int main()  
    {  
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>); // 创建点云（指针）  
      
        if (pcl::io::loadPCDFile<pcl::PointXYZRGB>("/home/cm/inputCloud0.pcd", *cloud) == -1) //* 读入PCD格式的文件，如果文件不存在，返回-1  
        {  
            PCL_ERROR("Couldn't read file test_pcd.pcd \n"); //文件不存在时，返回错误，终止程序。  
            return (-1);  
        }  
       
        pcl::visualization::CloudViewer viewer("pcd viewer");  
        viewer.showCloud (cloud);
        while (!viewer.wasStopped ())
           {
           }
        return 0;
    }  