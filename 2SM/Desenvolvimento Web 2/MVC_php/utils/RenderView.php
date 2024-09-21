<?php

class RenderView {
    public function loadView($view, $args) {
        extract($args);
        echo 'teste';
        require_once __DIR__ ."/../views/test.php";

    }
}