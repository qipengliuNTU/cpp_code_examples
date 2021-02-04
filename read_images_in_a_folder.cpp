
std::vector<cv::String> fn;

/*

void cv::glob(String pattern, std::vector< String > & result, bool recursive = false )	

*/

glob("/home/images/*.png", fn, false);
// or 
glob(dataPath + "/*.jpg", fn, false);

size_t count = fn.size(); 
for (size_t i=0; i<count; i++)
{
    std::cout << fn[i] << std::endl; 
    cv::Mat frame = imread(fn[i]);
    ...
}