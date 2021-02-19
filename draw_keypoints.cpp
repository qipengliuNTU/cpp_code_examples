    surf_detector->detectAndCompute(img, cv::Mat(), keys, descs);  // mask = cv::Mat()

    cv::Mat img_keys;
    cv::drawKeypoints( img, keys, img_keys );  // outputImage = img_keys 
    cv::imshow("Keypoints", img_keys );
    cv::waitKey();