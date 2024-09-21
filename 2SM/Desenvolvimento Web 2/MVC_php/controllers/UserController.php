<?php

require_once __DIR__."/../utils/RenderView.php";

class UserController extends RenderView {
    public function index() {
        echo 'user';
    }

    public function show($id) {

        $this->loadView(
            'test', 
            [
                "util" => "user"
            ]
        );

        echo 'user:::', print_r($id);
    }
}