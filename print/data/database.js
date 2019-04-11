$(document).ready(function(){
    fit();
    build();
    filter([], [], [], [], [], true);
    $('#search').submit(function(){
        var all = false;
        var generation = [];
        $('#query-generation option:selected').each(function(){
            var value = $(this).val();
            if (value == "") {
                all = true;
            }
            else {
                generation.push(value);
            }
            return;
        });
        if (all) {
            generation = [];
        }
        else {
            generation = generation.filter(function(x, i, self){
                return (self.indexOf(x) === i);
            });
        }
        all = false;
        var lab = [];
        $('#query-lab option:selected').each(function(){
            var value = $(this).val();
            if (value == "") {
                all = true;
            }
            else if (value == "media") {
                lab.push("Media-Lab");
                lab.push("B-Lab");
                lab.push("Studio-5");
            }
            else if (value == "image") {
                lab.push("Image-Lab");
                lab.push("C-Lab");
                lab.push("E-Lab");
                lab.push("Studio-6");
            }
            else if (value == "future") {
                lab.push("Future-Lab");
                lab.push("A-Lab");
                lab.push("D-Lab");
                lab.push("Studio-2");
                lab.push("Studio-6");
            }
            else {
                lab.push(value);
            }
            return;
        });
        if (all) {
            lab = [];
        }
        else {
            lab = lab.filter(function(x, i, self){
                return (self.indexOf(x) === i);
            });
        }
        all = false;
        var style = [];
        $('#query-style option:selected').each(function(){
            var value = $(this).val();
            if (value == "") {
                all = true;
            }
            else {
                style.push(value);
            }
            return;
        });
        if (all) {
            style = [];
        }
        else {
            style = style.filter(function(x, i, self){
                return (self.indexOf(x) === i);
            });
        }
        all = false;
        var name = [];
        $('#query-name option:selected').each(function(){
            var value = $(this).val();
            if (value == "") {
                all = true;
            }
            else {
                name.push(value);
            }
            return;
        });
        if (all) {
            name = [];
        }
        else {
            name = name.filter(function(x, i, self){
                return (self.indexOf(x) === i);
            });
        }
        all = false;
        var color = [];
        $('#query-color option:selected').each(function(){
            var value = $(this).val();
            if (value == "") {
                all = true;
            }
            else {
                color.push(value);
            }
            return;
        });
        if (all) {
            color = [];
        }
        else {
            color = color.filter(function(x, i, self){
                return (self.indexOf(x) === i);
            });
        }
        if (filter(generation, lab, style, name, color, true) > 0) {
            $('.navbar-toggler').click();
            $(window).trigger('resize');
        }
        else {
            alert("一致する子猫が見つかりませんでした");
        }
        return false;
    });
    return;
});

$(window).resize(function(){
    fit();
    return;
});

function fit(){
    var width = $('.card:visible').width();
    $('.card-img-top').css({'width': width, 'height': width});
    return;
}

function build(){
    $('.card').css('visibility', 'visible');
    var row = $('.album .row');
    var col = row.children('div');
    for (var i = g_gwdb['student']['item'].length - 1; i >= 0; --i) {
        var db = g_gwdb['student']['item'][i];
        if (db['graduate'] == "1") {
            var item = col.clone();
            if (db['photo'] != null && db['photo'] != "") {
                item.find('.card-img-top').attr('href', "./" + db['id'] + "/thumbnail.jpg").attr('data-lightbox', db['id']).attr('data-title', db['name'] + "<br />" + db['titleJ']);
                item.find('#photo').removeAttr('data-src').attr('data-original', "./" + db['id'] + "/thumbnail.jpg");
            }
            item.find('#titleJ').text(db['titleJ']);
            item.find('#titleE').text(db['titleE']);
            item.find('#name').text(db['name']);
            item.find('#year').text(db['year']);
            item.find('#lab').text(db['lab']);
            item.find('#style').text(db['style'].split(",").join(", "));
            item.find('#material').text(db['material'].split(",").join(", "));
            item.find('#comment').text(db['comment']);
            item.find('#author').text(db['author'].split(",").join(", "));
            item.find('#button_open').data('href',db['id']).click(function(e){
                window.open($(this).data('href') + ".html", '_self');
                return false;
            });
            if (db['material'] != null && db['material'] != "") {
                item.find('#button_detail').click(function(e){
                    $(this).closest('.card-body').find('#select').hide().end().find('#detail').toggle();
                    return false;
                });
            }
            else {
                item.find('#button_detail').remove();
            }
            if (db['select'] == "1") {
                item.find('.card-body').css('background-color', '#fafaff');
                item.find('#button_select').click(function(e){
                    $(this).closest('.card-body').find('#detail').hide().end().find('#select').toggle();
                    return false;
                });
            }
            else {
                item.find('#button_select').remove();
            }
            item.find('.card').data({'id': db['id'], 'lab': db['lab'], 'style': db['style'],'name':db['name'],'color':db['color'].split(","), 'select': db['select']});
            row.append(item);
        }
    }
    col.remove();
    $('img.lazyload').lazyload({threshold: 256, effect: 'fadeIn'});
    return;
}

function filter(generation, lab, style, name, color, select){
    var result = 0;
    $('.card').each(function(){
        var gen_match = false;
        if (generation.length > 0) {
            for (var i = 0; i < generation.length; ++i) {
                if ($(this).data('id').substr(0, 3) == generation[i].substr(0, 3)) {
                    gen_match = true;
                    break;
                }
            }
        }
        else {
            gen_match = true;
        }
        var lab_match = false;
        if (lab.length > 0) {
            for (var i = 0; i < lab.length; ++i) {
                if ($(this).data('lab') == lab[i]) {
                    lab_match = true;
                    break;
                }
            }
        }
        else {
            lab_match = true;
        }
        var style_match = false;
        if (style.length > 0) {
            for (var i = 0; i < style.length; ++i) {
                if ($(this).data('style').includes(style[i])) {
                    style_match = true;
                    break;
                }
            }
        }
        else {
            style_match = true;
        }
        var name_match = false;
        if (name.length > 0) {
            for (var i = 0; i < name.length; ++i) {
                if ($(this).data('name').includes(name[i])) {
                    name_match = true;
                    break;
                }
            }
        }
        else {
            name_match = true;
        }
        var color_match = false;
        if (color.length > 0) {
            for (var i = 0; i < color.length; ++i) {
                if ($(this).data('color').includes(color[i])) {
                    color_match = true;
                    break;
                }
            }
        }
        else {
            color_match = true;
        }
        if (gen_match && lab_match && style_match && name_match && color_match && (!select || (select && $(this).data('select') == "1"))) {
            $(this).parent().show();
            ++result;
        }
        else {
            $(this).parent().hide();
        }
        return;
    });
    return result;
}
