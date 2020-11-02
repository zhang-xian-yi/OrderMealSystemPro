/*
Navicat MySQL Data Transfer

Source Server         : AliyunMysql
Source Server Version : 50731
Source Host           : 39.96.8.207:3306
Source Database       : orderSys

Target Server Type    : MYSQL
Target Server Version : 50731
File Encoding         : 65001

Date: 2020-11-02 15:27:16
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for db_employer
-- ----------------------------
DROP TABLE IF EXISTS `db_employer`;
CREATE TABLE `db_employer` (
  `id` int(11) NOT NULL,
  `profess` int(11) NOT NULL,
  `name` varchar(32) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of db_employer
-- ----------------------------
INSERT INTO `db_employer` VALUES ('101', '2', 'zxy', '123456');
INSERT INTO `db_employer` VALUES ('102', '2', 'wds', '123456');
INSERT INTO `db_employer` VALUES ('103', '3', 'wc', '123456');
INSERT INTO `db_employer` VALUES ('104', '4', 'jql', '123456');
INSERT INTO `db_employer` VALUES ('105', '5', 'dj', '123456');

-- ----------------------------
-- Table structure for db_food_menu
-- ----------------------------
DROP TABLE IF EXISTS `db_food_menu`;
CREATE TABLE `db_food_menu` (
  `uuid` int(11) NOT NULL,
  `name` varchar(32) NOT NULL,
  `type` int(11) NOT NULL,
  `price` decimal(6,2) NOT NULL,
  `detail` varchar(255) NOT NULL,
  `imgurl` varchar(255) NOT NULL,
  PRIMARY KEY (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of db_food_menu
-- ----------------------------
INSERT INTO `db_food_menu` VALUES ('1', '烧鱼头', '2', '20.00', '锅中铺放牛蒡、姜片，放入作法1的鱼块、香菇，倒入作法3的煮汁，盖上小于锅子的锅盖；在煮的过程中可将煮汁用汤杓舀起，边煮边淋在鱼块上，使鱼平均上色', 'http://www.zhangxianyi4work.work:8088/orderSys/food/meat/hsyt.jpg');
INSERT INTO `db_food_menu` VALUES ('2', '回锅肉', '2', '15.00', '回锅肉口味独特，色泽红亮，肥而不腻，入口浓香', 'http://www.zhangxianyi4work.work:8088/orderSys/food/meat/hgr.jpg');
INSERT INTO `db_food_menu` VALUES ('3', '啤酒鸭', '2', '25.00', '主料为鸭子、啤酒。将鸭肉与啤酒一同炖煮成菜，使滋补的鸭肉味道更加浓厚，鸭肉不仅入口鲜香，还带有一股啤酒清香', 'http://www.zhangxianyi4work.work:8088/orderSys/food/meat/pjy.jpg');
INSERT INTO `db_food_menu` VALUES ('4', '鱼头煲', '2', '18.00', '大花鲢鱼头洗净后劈成两半放入大盆子中，加入葱姜蒜和白酒腌制两个小时', 'http://www.zhangxianyi4work.work:8088/orderSys/food/meat/ytb.jpg');
INSERT INTO `db_food_menu` VALUES ('5', '酒香鸡', '2', '25.00', '仔公鸡洗干净之后焯水，放入汤锅之中，加入糯米甜酒', 'http://www.zhangxianyi4work.work:8088/orderSys/food/meat/jxj.jpg');
INSERT INTO `db_food_menu` VALUES ('6', '一品馋嘴鱼', '2', '34.00', '将碱面放入热水中煮成八成熟时，捞出来用凉水冷却。将杀好的鱼放入锅中，在背部来上几刀', 'http://www.zhangxianyi4work.work:8088/orderSys/food/meat/ypczy.jpg');
INSERT INTO `db_food_menu` VALUES ('7', '豆奶', '1', '5.00', '养颜快乐水', 'http://www.zhangxianyi4work.work:8088/orderSys/food/drink/dn.jpg');
INSERT INTO `db_food_menu` VALUES ('8', '可乐', '1', '5.00', '肥仔快乐水', 'http://www.zhangxianyi4work.work:8088/orderSys/food/drink/kl.jpg');
INSERT INTO `db_food_menu` VALUES ('9', '奶茶', '1', '5.00', '宝物水', 'http://www.zhangxianyi4work.work:8088/orderSys/food/drink/nc.jpg');
INSERT INTO `db_food_menu` VALUES ('10', '啤酒', '1', '5.00', '男人的最好的伙伴', 'http://www.zhangxianyi4work.work:8088/orderSys/food/drink/pj.jpg');
INSERT INTO `db_food_menu` VALUES ('11', '雪碧', '1', '5.00', '汽水饮料', 'http://www.zhangxianyi4work.work:8088/orderSys/food/drink/xb.jpg');
INSERT INTO `db_food_menu` VALUES ('12', '雪花', '1', '10.00', '不一样的啤酒', 'http://www.zhangxianyi4work.work:8088/orderSys/food/drink/xh.jpg');

-- ----------------------------
-- Table structure for db_food_type
-- ----------------------------
DROP TABLE IF EXISTS `db_food_type`;
CREATE TABLE `db_food_type` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of db_food_type
-- ----------------------------
INSERT INTO `db_food_type` VALUES ('1', 'drink');
INSERT INTO `db_food_type` VALUES ('2', 'meat');
INSERT INTO `db_food_type` VALUES ('3', 'noodles');
INSERT INTO `db_food_type` VALUES ('4', 'soup');
INSERT INTO `db_food_type` VALUES ('5', 'vegetable');

-- ----------------------------
-- Table structure for db_professional
-- ----------------------------
DROP TABLE IF EXISTS `db_professional`;
CREATE TABLE `db_professional` (
  `uuid` int(11) NOT NULL,
  `name` varchar(32) NOT NULL,
  `permissions` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of db_professional
-- ----------------------------
INSERT INTO `db_professional` VALUES ('1', 'visitor', '0');
INSERT INTO `db_professional` VALUES ('2', 'servier', '1');
INSERT INTO `db_professional` VALUES ('3', 'counter', '1');
INSERT INTO `db_professional` VALUES ('4', 'cooker', '1');
INSERT INTO `db_professional` VALUES ('5', 'manager', '2');
