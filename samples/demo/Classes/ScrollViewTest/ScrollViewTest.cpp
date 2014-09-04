#include "ScrollViewTest.h"

#define CAColor_blueStyle ccc4(51,204,255,255)

ScrollViewTest::ScrollViewTest()
{

}

ScrollViewTest::~ScrollViewTest()
{

}

void ScrollViewTest::viewDidLoad()
{
	size = this->getView()->getBounds().size;
	
	p_ScrollView = CAScrollView::createWithCenter(CADipRect(size.width*0.5,size.height*0.5,size.width,size.height));
	p_ScrollView->setMinimumZoomScale(5.0f);
	p_ScrollView->setMaximumZoomScale(2.0f);
	this->getView()->addSubview(p_ScrollView);

	CADipSize _size = p_ScrollView->getBounds().size;
	imageView = CAImageView::createWithImage(CAImage::create("bg.jpg"));
	imageView->setCenterOrigin(CCPoint(_size.width*0.5, _size.height*0.5));
	p_ScrollView->addSubview(imageView);

	zoomView = CASlider::createWithCenter(CADipRect(size.width*0.5, size.height*0.9, size.width*0.8, 10));
	zoomView->addTarget(this,CAControl_selector(ScrollViewTest::zoomViewBySliderValue));
	this->getView()->addSubview(zoomView);
}

void ScrollViewTest::zoomViewBySliderValue(CAControl* btn, CCPoint point)
{
	float multiple = zoomView->getValue()+1.0;
	imageView->setScale(multiple);
}

void ScrollViewTest::viewDidUnload()
{

}